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
struct watchdog_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __booke_wdt_disable ; 
 int /*<<< orphan*/  on_each_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 

__attribute__((used)) static int booke_wdt_stop(struct watchdog_device *wdog)
{
	on_each_cpu(__booke_wdt_disable, NULL, 0);
	pr_debug("watchdog disabled\n");

	return 0;
}