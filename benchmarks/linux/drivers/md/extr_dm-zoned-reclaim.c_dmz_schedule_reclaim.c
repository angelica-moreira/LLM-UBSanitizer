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
struct dmz_reclaim {int /*<<< orphan*/  work; int /*<<< orphan*/  wq; } ;

/* Variables and functions */
 scalar_t__ dmz_should_reclaim (struct dmz_reclaim*) ; 
 int /*<<< orphan*/  mod_delayed_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void dmz_schedule_reclaim(struct dmz_reclaim *zrc)
{
	if (dmz_should_reclaim(zrc))
		mod_delayed_work(zrc->wq, &zrc->work, 0);
}