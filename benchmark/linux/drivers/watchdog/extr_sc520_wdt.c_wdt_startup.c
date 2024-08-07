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
 int HZ ; 
 int WDT_ENB ; 
 int WDT_EXP_SEL_04 ; 
 scalar_t__ WDT_INTERVAL ; 
 int WDT_WRST_ENB ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ next_heartbeat ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int timeout ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  wdt_config (int) ; 

__attribute__((used)) static int wdt_startup(void)
{
	next_heartbeat = jiffies + (timeout * HZ);

	/* Start the timer */
	mod_timer(&timer, jiffies + WDT_INTERVAL);

	/* Start the watchdog */
	wdt_config(WDT_ENB | WDT_WRST_ENB | WDT_EXP_SEL_04);

	pr_info("Watchdog timer is now enabled\n");
	return 0;
}