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
 int /*<<< orphan*/  device_initialize (int /*<<< orphan*/ *) ; 
 int platform_device_add (struct platform_device*) ; 
 int /*<<< orphan*/  setup_pdev_dma_masks (struct platform_device*) ; 

int platform_device_register(struct platform_device *pdev)
{
	device_initialize(&pdev->dev);
	setup_pdev_dma_masks(pdev);
	return platform_device_add(pdev);
}