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
struct usb_hcd {int dummy; } ;

/* Variables and functions */
 int xhci_gen_setup (struct usb_hcd*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xhci_plat_quirks ; 
 int xhci_priv_init_quirk (struct usb_hcd*) ; 

__attribute__((used)) static int xhci_plat_setup(struct usb_hcd *hcd)
{
	int ret;


	ret = xhci_priv_init_quirk(hcd);
	if (ret)
		return ret;

	return xhci_gen_setup(hcd, xhci_plat_quirks);
}