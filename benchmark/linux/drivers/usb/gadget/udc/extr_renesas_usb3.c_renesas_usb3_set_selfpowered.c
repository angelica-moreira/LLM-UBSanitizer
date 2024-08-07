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
struct usb_gadget {int is_selfpowered; } ;

/* Variables and functions */

__attribute__((used)) static int renesas_usb3_set_selfpowered(struct usb_gadget *gadget, int is_self)
{
	gadget->is_selfpowered = !!is_self;

	return 0;
}