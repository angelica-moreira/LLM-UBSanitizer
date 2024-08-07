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
struct tc_netem_corrupt {int /*<<< orphan*/  correlation; int /*<<< orphan*/  probability; } ;
struct nlattr {int dummy; } ;
struct netem_sched_data {int /*<<< orphan*/  corrupt_cor; int /*<<< orphan*/  corrupt; } ;

/* Variables and functions */
 int /*<<< orphan*/  init_crandom (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct tc_netem_corrupt* nla_data (struct nlattr const*) ; 

__attribute__((used)) static void get_corrupt(struct netem_sched_data *q, const struct nlattr *attr)
{
	const struct tc_netem_corrupt *r = nla_data(attr);

	q->corrupt = r->probability;
	init_crandom(&q->corrupt_cor, r->correlation);
}