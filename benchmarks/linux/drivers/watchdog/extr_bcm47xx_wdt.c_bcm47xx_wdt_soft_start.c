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
struct bcm47xx_wdt {int /*<<< orphan*/  soft_timer; } ;

/* Variables and functions */
 struct bcm47xx_wdt* bcm47xx_wdt_get (struct watchdog_device*) ; 
 int /*<<< orphan*/  bcm47xx_wdt_soft_keepalive (struct watchdog_device*) ; 
 int /*<<< orphan*/  bcm47xx_wdt_soft_timer_tick (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int bcm47xx_wdt_soft_start(struct watchdog_device *wdd)
{
	struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);

	bcm47xx_wdt_soft_keepalive(wdd);
	bcm47xx_wdt_soft_timer_tick(&wdt->soft_timer);

	return 0;
}