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
struct urb {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  usb_kill_urb (struct urb*) ; 

__attribute__((used)) static void usbduxsigma_unlink_urbs(struct urb **urbs, int num_urbs)
{
	int i;

	for (i = 0; i < num_urbs; i++)
		usb_kill_urb(urbs[i]);
}