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
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  device_init_wakeup (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int int0002_remove(struct platform_device *pdev)
{
	device_init_wakeup(&pdev->dev, false);
	return 0;
}