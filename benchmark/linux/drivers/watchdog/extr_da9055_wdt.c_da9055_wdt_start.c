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
struct watchdog_device {int /*<<< orphan*/  timeout; } ;

/* Variables and functions */
 int da9055_wdt_set_timeout (struct watchdog_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int da9055_wdt_start(struct watchdog_device *wdt_dev)
{
	return da9055_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
}