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
struct octeon_hcd {int /*<<< orphan*/  lock; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  cvmx_usb_poll (struct octeon_hcd*) ; 
 struct octeon_hcd* hcd_to_octeon (struct usb_hcd*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static irqreturn_t octeon_usb_irq(struct usb_hcd *hcd)
{
	struct octeon_hcd *usb = hcd_to_octeon(hcd);
	unsigned long flags;

	spin_lock_irqsave(&usb->lock, flags);
	cvmx_usb_poll(usb);
	spin_unlock_irqrestore(&usb->lock, flags);
	return IRQ_HANDLED;
}