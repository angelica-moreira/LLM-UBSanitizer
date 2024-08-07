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
struct hci_dev {int /*<<< orphan*/  power_led; } ;

/* Variables and functions */
 int /*<<< orphan*/  led_allocate_basic (struct hci_dev*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  power_activate ; 

void hci_leds_init(struct hci_dev *hdev)
{
	/* initialize power_led */
	hdev->power_led = led_allocate_basic(hdev, power_activate, "power");
}