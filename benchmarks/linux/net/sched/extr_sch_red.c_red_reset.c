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
struct red_sched_data {int /*<<< orphan*/  vars; int /*<<< orphan*/  qdisc; } ;
struct TYPE_4__ {scalar_t__ qlen; } ;
struct TYPE_3__ {scalar_t__ backlog; } ;
struct Qdisc {TYPE_2__ q; TYPE_1__ qstats; } ;

/* Variables and functions */
 struct red_sched_data* qdisc_priv (struct Qdisc*) ; 
 int /*<<< orphan*/  qdisc_reset (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  red_restart (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void red_reset(struct Qdisc *sch)
{
	struct red_sched_data *q = qdisc_priv(sch);

	qdisc_reset(q->qdisc);
	sch->qstats.backlog = 0;
	sch->q.qlen = 0;
	red_restart(&q->vars);
}