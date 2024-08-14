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
struct net_device {int dummy; } ;
struct catc {int /*<<< orphan*/  timer; int /*<<< orphan*/  is_f5u011; TYPE_1__* usbdev; TYPE_2__* irq_urb; } ;
struct TYPE_4__ {TYPE_1__* dev; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ STATS_UPDATE ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 struct catc* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int usb_submit_urb (TYPE_2__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int catc_open(struct net_device *netdev)
{
	struct catc *catc = netdev_priv(netdev);
	int status;

	catc->irq_urb->dev = catc->usbdev;
	if ((status = usb_submit_urb(catc->irq_urb, GFP_KERNEL)) < 0) {
		dev_err(&catc->usbdev->dev, "submit(irq_urb) status %d\n",
			status);
		return -1;
	}

	netif_start_queue(netdev);

	if (!catc->is_f5u011)
		mod_timer(&catc->timer, jiffies + STATS_UPDATE);

	return 0;
}