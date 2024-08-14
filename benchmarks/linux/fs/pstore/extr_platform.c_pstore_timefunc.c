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
struct timer_list {int dummy; } ;

/* Variables and functions */
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (scalar_t__) ; 
 scalar_t__ pstore_new_entry ; 
 int /*<<< orphan*/  pstore_timer ; 
 scalar_t__ pstore_update_ms ; 
 int /*<<< orphan*/  pstore_work ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void pstore_timefunc(struct timer_list *unused)
{
	if (pstore_new_entry) {
		pstore_new_entry = 0;
		schedule_work(&pstore_work);
	}

	if (pstore_update_ms >= 0)
		mod_timer(&pstore_timer,
			  jiffies + msecs_to_jiffies(pstore_update_ms));
}