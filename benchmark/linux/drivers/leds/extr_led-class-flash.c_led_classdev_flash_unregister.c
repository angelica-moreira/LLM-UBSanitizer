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
struct led_classdev_flash {int /*<<< orphan*/  led_cdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  led_classdev_unregister (int /*<<< orphan*/ *) ; 

void led_classdev_flash_unregister(struct led_classdev_flash *fled_cdev)
{
	if (!fled_cdev)
		return;

	led_classdev_unregister(&fled_cdev->led_cdev);
}