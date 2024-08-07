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
struct scsi_qla_host {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/ * sp; } ;
struct TYPE_4__ {TYPE_1__ iosb; } ;
struct qla_work_evt {TYPE_2__ u; } ;
typedef  int /*<<< orphan*/  srb_t ;

/* Variables and functions */
 int QLA_EVT_GNNFT_DONE ; 
 int QLA_EVT_GPNFT_DONE ; 
 int QLA_FUNCTION_FAILED ; 
 int QLA_PARAMETER_ERROR ; 
 struct qla_work_evt* qla2x00_alloc_work (struct scsi_qla_host*,int) ; 
 int qla2x00_post_work (struct scsi_qla_host*,struct qla_work_evt*) ; 

__attribute__((used)) static int qla2x00_post_gnnft_gpnft_done_work(struct scsi_qla_host *vha,
    srb_t *sp, int cmd)
{
	struct qla_work_evt *e;

	if (cmd != QLA_EVT_GPNFT_DONE && cmd != QLA_EVT_GNNFT_DONE)
		return QLA_PARAMETER_ERROR;

	e = qla2x00_alloc_work(vha, cmd);
	if (!e)
		return QLA_FUNCTION_FAILED;

	e->u.iosb.sp = sp;

	return qla2x00_post_work(vha, e);
}