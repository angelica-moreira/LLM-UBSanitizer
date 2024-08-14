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
 int wdt_update_timeout (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int wdt_stop(struct watchdog_device *wdd)
{
	return wdt_update_timeout(0);
}