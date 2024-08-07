#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint32_t ;
struct timer_list {int dummy; } ;
struct lpfc_vport {int work_port_events; int load_flag; int /*<<< orphan*/  work_port_lock; struct lpfc_hba* phba; } ;
struct lpfc_hba {int dummy; } ;

/* Variables and functions */
 int FC_UNLOADING ; 
 int WORKER_ELS_TMO ; 
 int /*<<< orphan*/  els_tmofunc ; 
 struct lpfc_vport* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lpfc_worker_wake_up (struct lpfc_hba*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct lpfc_vport* vport ; 

void
lpfc_els_timeout(struct timer_list *t)
{
	struct lpfc_vport *vport = from_timer(vport, t, els_tmofunc);
	struct lpfc_hba   *phba = vport->phba;
	uint32_t tmo_posted;
	unsigned long iflag;

	spin_lock_irqsave(&vport->work_port_lock, iflag);
	tmo_posted = vport->work_port_events & WORKER_ELS_TMO;
	if ((!tmo_posted) && (!(vport->load_flag & FC_UNLOADING)))
		vport->work_port_events |= WORKER_ELS_TMO;
	spin_unlock_irqrestore(&vport->work_port_lock, iflag);

	if ((!tmo_posted) && (!(vport->load_flag & FC_UNLOADING)))
		lpfc_worker_wake_up(phba);
	return;
}