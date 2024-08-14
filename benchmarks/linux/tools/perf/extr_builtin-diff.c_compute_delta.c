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
struct TYPE_4__ {double period_ratio_delta; int computed; } ;
struct TYPE_3__ {int /*<<< orphan*/  period; } ;
struct hist_entry {TYPE_2__ diff; TYPE_1__ stat; } ;

/* Variables and functions */
 double period_percent (struct hist_entry*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static double compute_delta(struct hist_entry *he, struct hist_entry *pair)
{
	double old_percent = period_percent(he, he->stat.period);
	double new_percent = period_percent(pair, pair->stat.period);

	pair->diff.period_ratio_delta = new_percent - old_percent;
	pair->diff.computed = true;
	return pair->diff.period_ratio_delta;
}