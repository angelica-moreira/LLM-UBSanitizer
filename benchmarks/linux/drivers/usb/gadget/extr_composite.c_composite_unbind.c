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
struct usb_gadget {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __composite_unbind (struct usb_gadget*,int) ; 

__attribute__((used)) static void composite_unbind(struct usb_gadget *gadget)
{
	__composite_unbind(gadget, true);
}