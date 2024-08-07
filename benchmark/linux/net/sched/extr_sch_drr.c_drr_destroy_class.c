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
struct drr_class {int /*<<< orphan*/  qdisc; int /*<<< orphan*/  rate_est; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gen_kill_estimator (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct drr_class*) ; 
 int /*<<< orphan*/  qdisc_put (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void drr_destroy_class(struct Qdisc *sch, struct drr_class *cl)
{
	gen_kill_estimator(&cl->rate_est);
	qdisc_put(cl->qdisc);
	kfree(cl);
}