#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct scsi_qla_host {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  opt; TYPE_3__* fcport; } ;
struct TYPE_6__ {TYPE_1__ fcport; } ;
struct qla_work_evt {TYPE_2__ u; } ;
struct TYPE_7__ {int /*<<< orphan*/  flags; } ;
typedef  TYPE_3__ fc_port_t ;

/* Variables and functions */
 int /*<<< orphan*/  FCF_ASYNC_ACTIVE ; 
 int /*<<< orphan*/  QLA_EVT_GPDB ; 
 int QLA_FUNCTION_FAILED ; 
 struct qla_work_evt* qla2x00_alloc_work (struct scsi_qla_host*,int /*<<< orphan*/ ) ; 
 int qla2x00_post_work (struct scsi_qla_host*,struct qla_work_evt*) ; 

int qla24xx_post_gpdb_work(struct scsi_qla_host *vha, fc_port_t *fcport, u8 opt)
{
	struct qla_work_evt *e;

	e = qla2x00_alloc_work(vha, QLA_EVT_GPDB);
	if (!e)
		return QLA_FUNCTION_FAILED;

	e->u.fcport.fcport = fcport;
	e->u.fcport.opt = opt;
	fcport->flags |= FCF_ASYNC_ACTIVE;
	return qla2x00_post_work(vha, e);
}