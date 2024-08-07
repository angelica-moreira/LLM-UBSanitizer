#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct srb_iocb {int /*<<< orphan*/  timer; } ;
struct TYPE_5__ {struct srb_iocb iocb_cmd; } ;
struct TYPE_6__ {TYPE_1__ u; } ;
typedef  TYPE_2__ srb_t ;

/* Variables and functions */
 int /*<<< orphan*/  del_timer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qla2x00_rel_sp (TYPE_2__*) ; 

void qla2x00_sp_free(srb_t *sp)
{
	struct srb_iocb *iocb = &sp->u.iocb_cmd;

	del_timer(&iocb->timer);
	qla2x00_rel_sp(sp);
}