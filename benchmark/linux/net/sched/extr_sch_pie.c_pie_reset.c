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
struct pie_sched_data {int /*<<< orphan*/  vars; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pie_vars_init (int /*<<< orphan*/ *) ; 
 struct pie_sched_data* qdisc_priv (struct Qdisc*) ; 
 int /*<<< orphan*/  qdisc_reset_queue (struct Qdisc*) ; 

__attribute__((used)) static void pie_reset(struct Qdisc *sch)
{
	struct pie_sched_data *q = qdisc_priv(sch);

	qdisc_reset_queue(sch);
	pie_vars_init(&q->vars);
}