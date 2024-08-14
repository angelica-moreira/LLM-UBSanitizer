#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  timer; } ;

/* Variables and functions */
 TYPE_1__ bcm63xx_wdt_device ; 
 int /*<<< orphan*/  bcm63xx_wdt_hw_stop () ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void bcm63xx_wdt_pause(void)
{
	del_timer_sync(&bcm63xx_wdt_device.timer);
	bcm63xx_wdt_hw_stop();
}