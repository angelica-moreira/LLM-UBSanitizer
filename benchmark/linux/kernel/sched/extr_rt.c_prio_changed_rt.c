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
struct task_struct {int prio; } ;
struct TYPE_3__ {scalar_t__ curr; } ;
struct TYPE_4__ {TYPE_1__ highest_prio; } ;
struct rq {struct task_struct* curr; TYPE_2__ rt; } ;

/* Variables and functions */
 int /*<<< orphan*/  resched_curr (struct rq*) ; 
 int /*<<< orphan*/  rt_queue_pull_task (struct rq*) ; 
 int /*<<< orphan*/  task_on_rq_queued (struct task_struct*) ; 

__attribute__((used)) static void
prio_changed_rt(struct rq *rq, struct task_struct *p, int oldprio)
{
	if (!task_on_rq_queued(p))
		return;

	if (rq->curr == p) {
#ifdef CONFIG_SMP
		/*
		 * If our priority decreases while running, we
		 * may need to pull tasks to this runqueue.
		 */
		if (oldprio < p->prio)
			rt_queue_pull_task(rq);

		/*
		 * If there's a higher priority task waiting to run
		 * then reschedule.
		 */
		if (p->prio > rq->rt.highest_prio.curr)
			resched_curr(rq);
#else
		/* For UP simply resched on drop of prio */
		if (oldprio < p->prio)
			resched_curr(rq);
#endif /* CONFIG_SMP */
	} else {
		/*
		 * This task is not running, but if it is
		 * greater than the current running task
		 * then reschedule.
		 */
		if (p->prio < rq->curr->prio)
			resched_curr(rq);
	}
}