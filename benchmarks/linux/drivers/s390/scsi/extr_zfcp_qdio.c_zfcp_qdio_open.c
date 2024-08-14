#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct zfcp_qdio {int max_sbale_per_sbal; int max_sbale_per_req; struct zfcp_adapter* adapter; int /*<<< orphan*/  req_q_free; scalar_t__ req_q_idx; TYPE_1__** res_q; } ;
struct zfcp_adapter {TYPE_2__* scsi_host; int /*<<< orphan*/  status; struct ccw_device* ccw_device; } ;
struct qdio_ssqd_desc {int qdioac2; } ;
struct qdio_initialize {int /*<<< orphan*/  cdev; } ;
struct qdio_buffer_element {int /*<<< orphan*/ * addr; scalar_t__ sflags; int /*<<< orphan*/  eflags; scalar_t__ length; } ;
struct ccw_device {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int sg_tablesize; int max_sectors; } ;
struct TYPE_3__ {struct qdio_buffer_element* element; } ;

/* Variables and functions */
 int CHSC_AC2_DATA_DIV_ENABLED ; 
 int CHSC_AC2_MULTI_BUFFER_ENABLED ; 
 int EIO ; 
 int /*<<< orphan*/  QDIO_FLAG_CLEANUP_USING_CLEAR ; 
 int /*<<< orphan*/  QDIO_FLAG_SYNC_INPUT ; 
 int QDIO_MAX_BUFFERS_PER_Q ; 
 void* QDIO_MAX_ELEMENTS_PER_BUFFER ; 
 int /*<<< orphan*/  SBAL_EFLAGS_LAST_ENTRY ; 
 int ZFCP_QDIO_MAX_SBALS_PER_REQ ; 
 int ZFCP_STATUS_ADAPTER_DATA_DIV_ENABLED ; 
 int ZFCP_STATUS_ADAPTER_MB_ACT ; 
 int ZFCP_STATUS_ADAPTER_QDIOUP ; 
 int ZFCP_STATUS_ADAPTER_SIOSL_ISSUED ; 
 int /*<<< orphan*/  atomic_andnot (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_or (int,int /*<<< orphan*/ *) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ do_QDIO (struct ccw_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ qdio_activate (struct ccw_device*) ; 
 scalar_t__ qdio_establish (struct qdio_initialize*) ; 
 scalar_t__ qdio_get_ssqd_desc (int /*<<< orphan*/ ,struct qdio_ssqd_desc*) ; 
 int /*<<< orphan*/  qdio_shutdown (struct ccw_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zfcp_qdio_setup_init_data (struct qdio_initialize*,struct zfcp_qdio*) ; 

int zfcp_qdio_open(struct zfcp_qdio *qdio)
{
	struct qdio_buffer_element *sbale;
	struct qdio_initialize init_data;
	struct zfcp_adapter *adapter = qdio->adapter;
	struct ccw_device *cdev = adapter->ccw_device;
	struct qdio_ssqd_desc ssqd;
	int cc;

	if (atomic_read(&adapter->status) & ZFCP_STATUS_ADAPTER_QDIOUP)
		return -EIO;

	atomic_andnot(ZFCP_STATUS_ADAPTER_SIOSL_ISSUED,
			  &qdio->adapter->status);

	zfcp_qdio_setup_init_data(&init_data, qdio);

	if (qdio_establish(&init_data))
		goto failed_establish;

	if (qdio_get_ssqd_desc(init_data.cdev, &ssqd))
		goto failed_qdio;

	if (ssqd.qdioac2 & CHSC_AC2_DATA_DIV_ENABLED)
		atomic_or(ZFCP_STATUS_ADAPTER_DATA_DIV_ENABLED,
				&qdio->adapter->status);

	if (ssqd.qdioac2 & CHSC_AC2_MULTI_BUFFER_ENABLED) {
		atomic_or(ZFCP_STATUS_ADAPTER_MB_ACT, &adapter->status);
		qdio->max_sbale_per_sbal = QDIO_MAX_ELEMENTS_PER_BUFFER;
	} else {
		atomic_andnot(ZFCP_STATUS_ADAPTER_MB_ACT, &adapter->status);
		qdio->max_sbale_per_sbal = QDIO_MAX_ELEMENTS_PER_BUFFER - 1;
	}

	qdio->max_sbale_per_req =
		ZFCP_QDIO_MAX_SBALS_PER_REQ * qdio->max_sbale_per_sbal
		- 2;
	if (qdio_activate(cdev))
		goto failed_qdio;

	for (cc = 0; cc < QDIO_MAX_BUFFERS_PER_Q; cc++) {
		sbale = &(qdio->res_q[cc]->element[0]);
		sbale->length = 0;
		sbale->eflags = SBAL_EFLAGS_LAST_ENTRY;
		sbale->sflags = 0;
		sbale->addr = NULL;
	}

	if (do_QDIO(cdev, QDIO_FLAG_SYNC_INPUT, 0, 0, QDIO_MAX_BUFFERS_PER_Q))
		goto failed_qdio;

	/* set index of first available SBALS / number of available SBALS */
	qdio->req_q_idx = 0;
	atomic_set(&qdio->req_q_free, QDIO_MAX_BUFFERS_PER_Q);
	atomic_or(ZFCP_STATUS_ADAPTER_QDIOUP, &qdio->adapter->status);

	if (adapter->scsi_host) {
		adapter->scsi_host->sg_tablesize = qdio->max_sbale_per_req;
		adapter->scsi_host->max_sectors = qdio->max_sbale_per_req * 8;
	}

	return 0;

failed_qdio:
	qdio_shutdown(cdev, QDIO_FLAG_CLEANUP_USING_CLEAR);
failed_establish:
	dev_err(&cdev->dev,
		"Setting up the QDIO connection to the FCP adapter failed\n");
	return -EIO;
}