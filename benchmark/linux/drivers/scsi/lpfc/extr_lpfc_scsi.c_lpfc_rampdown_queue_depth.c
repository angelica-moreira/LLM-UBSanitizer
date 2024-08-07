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
typedef  int uint32_t ;
struct lpfc_hba {unsigned long last_ramp_down_time; TYPE_1__* pport; int /*<<< orphan*/  hbalock; void* last_rsrc_error_time; int /*<<< orphan*/  num_rsrc_err; } ;
struct TYPE_2__ {int work_port_events; int /*<<< orphan*/  work_port_lock; } ;

/* Variables and functions */
 unsigned long QUEUE_RAMP_DOWN_INTERVAL ; 
 int WORKER_RAMP_DOWN_QUEUE ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 void* jiffies ; 
 int /*<<< orphan*/  lpfc_worker_wake_up (struct lpfc_hba*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ time_after (unsigned long,void*) ; 

void
lpfc_rampdown_queue_depth(struct lpfc_hba *phba)
{
	unsigned long flags;
	uint32_t evt_posted;
	unsigned long expires;

	spin_lock_irqsave(&phba->hbalock, flags);
	atomic_inc(&phba->num_rsrc_err);
	phba->last_rsrc_error_time = jiffies;

	expires = phba->last_ramp_down_time + QUEUE_RAMP_DOWN_INTERVAL;
	if (time_after(expires, jiffies)) {
		spin_unlock_irqrestore(&phba->hbalock, flags);
		return;
	}

	phba->last_ramp_down_time = jiffies;

	spin_unlock_irqrestore(&phba->hbalock, flags);

	spin_lock_irqsave(&phba->pport->work_port_lock, flags);
	evt_posted = phba->pport->work_port_events & WORKER_RAMP_DOWN_QUEUE;
	if (!evt_posted)
		phba->pport->work_port_events |= WORKER_RAMP_DOWN_QUEUE;
	spin_unlock_irqrestore(&phba->pport->work_port_lock, flags);

	if (!evt_posted)
		lpfc_worker_wake_up(phba);
	return;
}