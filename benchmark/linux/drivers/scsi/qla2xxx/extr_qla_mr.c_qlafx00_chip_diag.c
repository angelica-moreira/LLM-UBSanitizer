#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct req_que {int length; } ;
struct qla_hw_data {int fw_transfer_size; struct req_que** req_q_map; } ;
struct TYPE_5__ {struct qla_hw_data* hw; } ;
typedef  TYPE_1__ scsi_qla_host_t ;

/* Variables and functions */
 int QLA_SUCCESS ; 
 int REQUEST_ENTRY_SIZE ; 
 int /*<<< orphan*/  ql_log (int /*<<< orphan*/ ,TYPE_1__*,int,char*) ; 
 int /*<<< orphan*/  ql_log_warn ; 
 int qlafx00_mbx_reg_test (TYPE_1__*) ; 

int
qlafx00_chip_diag(scsi_qla_host_t *vha)
{
	int rval = 0;
	struct qla_hw_data *ha = vha->hw;
	struct req_que *req = ha->req_q_map[0];

	ha->fw_transfer_size = REQUEST_ENTRY_SIZE * req->length;

	rval = qlafx00_mbx_reg_test(vha);
	if (rval) {
		ql_log(ql_log_warn, vha, 0x1165,
		    "Failed mailbox send register test\n");
	} else {
		/* Flag a successful rval */
		rval = QLA_SUCCESS;
	}
	return rval;
}