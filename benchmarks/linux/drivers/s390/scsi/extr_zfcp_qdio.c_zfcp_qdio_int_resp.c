#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  scalar_t__ u64 ;
struct zfcp_qdio {struct zfcp_adapter* adapter; TYPE_1__** res_q; } ;
struct zfcp_adapter {int dummy; } ;
struct qdio_buffer_element {scalar_t__ scount; scalar_t__ addr; } ;
struct ccw_device {int dummy; } ;
struct TYPE_2__ {struct qdio_buffer_element* element; } ;

/* Variables and functions */
 int /*<<< orphan*/  QDIO_FLAG_SYNC_INPUT ; 
 int QDIO_MAX_BUFFERS_PER_Q ; 
 int ZFCP_QDIO_MAX_SBALS_PER_REQ ; 
 scalar_t__ do_QDIO (struct ccw_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  memset (void**,int /*<<< orphan*/ ,int) ; 
 int min (scalar_t__,int) ; 
 scalar_t__ unlikely (unsigned int) ; 
 scalar_t__ zfcp_adapter_multi_buffer_active (struct zfcp_adapter*) ; 
 int /*<<< orphan*/  zfcp_dbf_hba_def_err (struct zfcp_adapter*,scalar_t__,int,void**) ; 
 int /*<<< orphan*/  zfcp_erp_adapter_reopen (struct zfcp_adapter*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  zfcp_fsf_reqid_check (struct zfcp_qdio*,int) ; 
 int /*<<< orphan*/  zfcp_qdio_handler_error (struct zfcp_qdio*,char*,unsigned int) ; 

__attribute__((used)) static void zfcp_qdio_int_resp(struct ccw_device *cdev, unsigned int qdio_err,
			       int queue_no, int idx, int count,
			       unsigned long parm)
{
	struct zfcp_qdio *qdio = (struct zfcp_qdio *) parm;
	struct zfcp_adapter *adapter = qdio->adapter;
	int sbal_no, sbal_idx;

	if (unlikely(qdio_err)) {
		if (zfcp_adapter_multi_buffer_active(adapter)) {
			void *pl[ZFCP_QDIO_MAX_SBALS_PER_REQ + 1];
			struct qdio_buffer_element *sbale;
			u64 req_id;
			u8 scount;

			memset(pl, 0,
			       ZFCP_QDIO_MAX_SBALS_PER_REQ * sizeof(void *));
			sbale = qdio->res_q[idx]->element;
			req_id = (u64) sbale->addr;
			scount = min(sbale->scount + 1,
				     ZFCP_QDIO_MAX_SBALS_PER_REQ + 1);
				     /* incl. signaling SBAL */

			for (sbal_no = 0; sbal_no < scount; sbal_no++) {
				sbal_idx = (idx + sbal_no) %
					QDIO_MAX_BUFFERS_PER_Q;
				pl[sbal_no] = qdio->res_q[sbal_idx];
			}
			zfcp_dbf_hba_def_err(adapter, req_id, scount, pl);
		}
		zfcp_qdio_handler_error(qdio, "qdires1", qdio_err);
		return;
	}

	/*
	 * go through all SBALs from input queue currently
	 * returned by QDIO layer
	 */
	for (sbal_no = 0; sbal_no < count; sbal_no++) {
		sbal_idx = (idx + sbal_no) % QDIO_MAX_BUFFERS_PER_Q;
		/* go through all SBALEs of SBAL */
		zfcp_fsf_reqid_check(qdio, sbal_idx);
	}

	/*
	 * put SBALs back to response queue
	 */
	if (do_QDIO(cdev, QDIO_FLAG_SYNC_INPUT, 0, idx, count))
		zfcp_erp_adapter_reopen(qdio->adapter, 0, "qdires2");
}