#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct wa_xfer {TYPE_2__* wa; int /*<<< orphan*/  result; int /*<<< orphan*/  urb; int /*<<< orphan*/  list_node; } ;
struct TYPE_4__ {TYPE_1__* wusb; int /*<<< orphan*/  xfer_list_lock; } ;
struct TYPE_3__ {int /*<<< orphan*/  usb_hcd; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  usb_hcd_unlink_urb_from_ep (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wa_put (TYPE_2__*) ; 
 int /*<<< orphan*/  wa_xfer_put (struct wa_xfer*) ; 
 int /*<<< orphan*/  wusbhc_giveback_urb (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void wa_xfer_giveback(struct wa_xfer *xfer)
{
	unsigned long flags;

	spin_lock_irqsave(&xfer->wa->xfer_list_lock, flags);
	list_del_init(&xfer->list_node);
	usb_hcd_unlink_urb_from_ep(&(xfer->wa->wusb->usb_hcd), xfer->urb);
	spin_unlock_irqrestore(&xfer->wa->xfer_list_lock, flags);
	/* FIXME: segmentation broken -- kills DWA */
	wusbhc_giveback_urb(xfer->wa->wusb, xfer->urb, xfer->result);
	wa_put(xfer->wa);
	wa_xfer_put(xfer);
}