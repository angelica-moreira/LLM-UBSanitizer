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
struct sched_entity {int /*<<< orphan*/  vruntime; } ;
struct task_struct {struct sched_entity se; } ;
struct cfs_rq {scalar_t__ min_vruntime; } ;

/* Variables and functions */
 int /*<<< orphan*/  attach_entity_cfs_rq (struct sched_entity*) ; 
 struct cfs_rq* cfs_rq_of (struct sched_entity*) ; 
 int /*<<< orphan*/  vruntime_normalized (struct task_struct*) ; 

__attribute__((used)) static void attach_task_cfs_rq(struct task_struct *p)
{
	struct sched_entity *se = &p->se;
	struct cfs_rq *cfs_rq = cfs_rq_of(se);

	attach_entity_cfs_rq(se);

	if (!vruntime_normalized(p))
		se->vruntime += cfs_rq->min_vruntime;
}