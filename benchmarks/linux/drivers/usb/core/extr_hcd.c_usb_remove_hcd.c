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
struct TYPE_4__ {int /*<<< orphan*/  controller; struct usb_device* root_hub; } ;
struct usb_hcd {scalar_t__ irq; scalar_t__ flags; int /*<<< orphan*/  phy_roothub; TYPE_2__ self; int /*<<< orphan*/  rh_timer; int /*<<< orphan*/  state; TYPE_1__* driver; scalar_t__ rh_pollable; int /*<<< orphan*/  died_work; int /*<<< orphan*/  wakeup_work; scalar_t__ rh_registered; } ;
struct usb_device {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* stop ) (struct usb_hcd*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  HCD_FLAG_POLL_RH ; 
 int /*<<< orphan*/  HCD_FLAG_RH_RUNNING ; 
 scalar_t__ HC_IS_RUNNING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HC_STATE_HALT ; 
 int /*<<< orphan*/  HC_STATE_QUIESCING ; 
 int /*<<< orphan*/  cancel_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct usb_hcd*) ; 
 int /*<<< orphan*/  hcd_buffer_destroy (struct usb_hcd*) ; 
 int /*<<< orphan*/  hcd_root_hub_lock ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_bus_idr_lock ; 
 int /*<<< orphan*/  usb_deregister_bus (TYPE_2__*) ; 
 int /*<<< orphan*/  usb_disconnect (struct usb_device**) ; 
 int /*<<< orphan*/  usb_get_dev (struct usb_device*) ; 
 scalar_t__ usb_hcd_is_primary_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_phy_roothub_exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_phy_roothub_power_off (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_put_invalidate_rhdev (struct usb_hcd*) ; 

void usb_remove_hcd(struct usb_hcd *hcd)
{
	struct usb_device *rhdev = hcd->self.root_hub;

	dev_info(hcd->self.controller, "remove, state %x\n", hcd->state);

	usb_get_dev(rhdev);
	clear_bit(HCD_FLAG_RH_RUNNING, &hcd->flags);
	if (HC_IS_RUNNING (hcd->state))
		hcd->state = HC_STATE_QUIESCING;

	dev_dbg(hcd->self.controller, "roothub graceful disconnect\n");
	spin_lock_irq (&hcd_root_hub_lock);
	hcd->rh_registered = 0;
	spin_unlock_irq (&hcd_root_hub_lock);

#ifdef CONFIG_PM
	cancel_work_sync(&hcd->wakeup_work);
#endif
	cancel_work_sync(&hcd->died_work);

	mutex_lock(&usb_bus_idr_lock);
	usb_disconnect(&rhdev);		/* Sets rhdev to NULL */
	mutex_unlock(&usb_bus_idr_lock);

	/*
	 * tasklet_kill() isn't needed here because:
	 * - driver's disconnect() called from usb_disconnect() should
	 *   make sure its URBs are completed during the disconnect()
	 *   callback
	 *
	 * - it is too late to run complete() here since driver may have
	 *   been removed already now
	 */

	/* Prevent any more root-hub status calls from the timer.
	 * The HCD might still restart the timer (if a port status change
	 * interrupt occurs), but usb_hcd_poll_rh_status() won't invoke
	 * the hub_status_data() callback.
	 */
	hcd->rh_pollable = 0;
	clear_bit(HCD_FLAG_POLL_RH, &hcd->flags);
	del_timer_sync(&hcd->rh_timer);

	hcd->driver->stop(hcd);
	hcd->state = HC_STATE_HALT;

	/* In case the HCD restarted the timer, stop it again. */
	clear_bit(HCD_FLAG_POLL_RH, &hcd->flags);
	del_timer_sync(&hcd->rh_timer);

	if (usb_hcd_is_primary_hcd(hcd)) {
		if (hcd->irq > 0)
			free_irq(hcd->irq, hcd);
	}

	usb_deregister_bus(&hcd->self);
	hcd_buffer_destroy(hcd);

	usb_phy_roothub_power_off(hcd->phy_roothub);
	usb_phy_roothub_exit(hcd->phy_roothub);

	usb_put_invalidate_rhdev(hcd);
	hcd->flags = 0;
}