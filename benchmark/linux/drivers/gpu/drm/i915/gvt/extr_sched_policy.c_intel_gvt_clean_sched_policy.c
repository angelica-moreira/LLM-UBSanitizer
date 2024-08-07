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
struct TYPE_4__ {TYPE_1__* sched_ops; } ;
struct intel_gvt {int /*<<< orphan*/  sched_lock; TYPE_2__ scheduler; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* clean ) (struct intel_gvt*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct intel_gvt*) ; 

void intel_gvt_clean_sched_policy(struct intel_gvt *gvt)
{
	mutex_lock(&gvt->sched_lock);
	gvt->scheduler.sched_ops->clean(gvt);
	mutex_unlock(&gvt->sched_lock);
}