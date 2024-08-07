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
struct ohci_hcd {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  OHCI_QUIRK_ZFMICRO ; 
 struct ohci_hcd* hcd_to_ohci (struct usb_hcd*) ; 
 int /*<<< orphan*/  ohci_dbg (struct ohci_hcd*,char*) ; 

__attribute__((used)) static int ohci_quirk_zfmicro(struct usb_hcd *hcd)
{
	struct ohci_hcd	*ohci = hcd_to_ohci (hcd);

	ohci->flags |= OHCI_QUIRK_ZFMICRO;
	ohci_dbg(ohci, "enabled Compaq ZFMicro chipset quirks\n");

	return 0;
}