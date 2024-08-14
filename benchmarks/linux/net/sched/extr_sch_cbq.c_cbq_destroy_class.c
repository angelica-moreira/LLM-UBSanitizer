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
struct cbq_class {int /*<<< orphan*/  rate_est; int /*<<< orphan*/  R_tab; int /*<<< orphan*/  q; int /*<<< orphan*/  block; int /*<<< orphan*/  filters; } ;
struct cbq_sched_data {struct cbq_class link; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_kill_estimator (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct cbq_class*) ; 
 struct cbq_sched_data* qdisc_priv (struct Qdisc*) ; 
 int /*<<< orphan*/  qdisc_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qdisc_put_rtab (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tcf_block_put (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cbq_destroy_class(struct Qdisc *sch, struct cbq_class *cl)
{
	struct cbq_sched_data *q = qdisc_priv(sch);

	WARN_ON(cl->filters);

	tcf_block_put(cl->block);
	qdisc_put(cl->q);
	qdisc_put_rtab(cl->R_tab);
	gen_kill_estimator(&cl->rate_est);
	if (cl != &q->link)
		kfree(cl);
}