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
struct imx7ulp_wdt_device {scalar_t__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  REFRESH ; 
 scalar_t__ WDOG_CNT ; 
 struct imx7ulp_wdt_device* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int imx7ulp_wdt_ping(struct watchdog_device *wdog)
{
	struct imx7ulp_wdt_device *wdt = watchdog_get_drvdata(wdog);

	writel(REFRESH, wdt->base + WDOG_CNT);

	return 0;
}