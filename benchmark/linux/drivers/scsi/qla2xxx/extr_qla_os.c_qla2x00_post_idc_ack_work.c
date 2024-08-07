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
typedef  int /*<<< orphan*/  uint16_t ;
struct scsi_qla_host {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  mb; } ;
struct TYPE_4__ {TYPE_1__ idc_ack; } ;
struct qla_work_evt {TYPE_2__ u; } ;

/* Variables and functions */
 int /*<<< orphan*/  QLA_EVT_IDC_ACK ; 
 int QLA_FUNCTION_FAILED ; 
 int QLA_IDC_ACK_REGS ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 struct qla_work_evt* qla2x00_alloc_work (struct scsi_qla_host*,int /*<<< orphan*/ ) ; 
 int qla2x00_post_work (struct scsi_qla_host*,struct qla_work_evt*) ; 

int
qla2x00_post_idc_ack_work(struct scsi_qla_host *vha, uint16_t *mb)
{
	struct qla_work_evt *e;

	e = qla2x00_alloc_work(vha, QLA_EVT_IDC_ACK);
	if (!e)
		return QLA_FUNCTION_FAILED;

	memcpy(e->u.idc_ack.mb, mb, QLA_IDC_ACK_REGS * sizeof(uint16_t));
	return qla2x00_post_work(vha, e);
}