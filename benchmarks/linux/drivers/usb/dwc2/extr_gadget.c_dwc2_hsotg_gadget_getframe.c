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
 int dwc2_hsotg_read_frameno (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_hsotg (struct usb_gadget*) ; 

__attribute__((used)) static int dwc2_hsotg_gadget_getframe(struct usb_gadget *gadget)
{
	return dwc2_hsotg_read_frameno(to_hsotg(gadget));
}