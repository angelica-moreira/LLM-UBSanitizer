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
 int /*<<< orphan*/  del_timer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  wdt_config (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int wdt_turnoff(void)
{
	/* Stop the timer */
	del_timer(&timer);

	/* Stop the watchdog */
	wdt_config(0);

	pr_info("Watchdog timer is now disabled...\n");
	return 0;
}