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

/* Variables and functions */
 int /*<<< orphan*/  jiffies ; 
 int /*<<< orphan*/  rfkill_last_scheduled ; 
 int /*<<< orphan*/  rfkill_op_work ; 
 int /*<<< orphan*/  rfkill_ratelimit (int /*<<< orphan*/ ) ; 
 scalar_t__ schedule_delayed_work (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rfkill_schedule_ratelimited(void)
{
	if (schedule_delayed_work(&rfkill_op_work,
				  rfkill_ratelimit(rfkill_last_scheduled)))
		rfkill_last_scheduled = jiffies;
}