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
struct vudc_device {int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct vudc_device*) ; 
 int /*<<< orphan*/  platform_device_put (int /*<<< orphan*/ ) ; 

void put_vudc_device(struct vudc_device *udc_dev)
{
	platform_device_put(udc_dev->pdev);
	kfree(udc_dev);
}