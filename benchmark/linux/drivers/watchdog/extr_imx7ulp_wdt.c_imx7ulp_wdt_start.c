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
struct imx7ulp_wdt_device {int /*<<< orphan*/  base; } ;

/* Variables and functions */
 int /*<<< orphan*/  imx7ulp_wdt_enable (int /*<<< orphan*/ ,int) ; 
 struct imx7ulp_wdt_device* watchdog_get_drvdata (struct watchdog_device*) ; 

__attribute__((used)) static int imx7ulp_wdt_start(struct watchdog_device *wdog)
{
	struct imx7ulp_wdt_device *wdt = watchdog_get_drvdata(wdog);

	imx7ulp_wdt_enable(wdt->base, true);

	return 0;
}