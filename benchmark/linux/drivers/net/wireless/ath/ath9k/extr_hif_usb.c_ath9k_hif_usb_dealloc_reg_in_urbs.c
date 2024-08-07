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
struct hif_device_usb {int /*<<< orphan*/  reg_in_submitted; } ;

/* Variables and functions */
 int /*<<< orphan*/  usb_kill_anchored_urbs (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ath9k_hif_usb_dealloc_reg_in_urbs(struct hif_device_usb *hif_dev)
{
	usb_kill_anchored_urbs(&hif_dev->reg_in_submitted);
}