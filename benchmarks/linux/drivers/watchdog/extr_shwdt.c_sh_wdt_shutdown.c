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
struct platform_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sh_wdt_dev ; 
 int /*<<< orphan*/  sh_wdt_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sh_wdt_shutdown(struct platform_device *pdev)
{
	sh_wdt_stop(&sh_wdt_dev);
}