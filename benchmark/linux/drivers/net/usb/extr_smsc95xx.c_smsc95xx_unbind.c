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
struct usbnet {scalar_t__* data; int /*<<< orphan*/  net; } ;
struct usb_interface {int dummy; } ;
struct smsc95xx_priv {int /*<<< orphan*/  carrier_check; } ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_delayed_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ifdown ; 
 int /*<<< orphan*/  kfree (struct smsc95xx_priv*) ; 
 int /*<<< orphan*/  netif_dbg (struct usbnet*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void smsc95xx_unbind(struct usbnet *dev, struct usb_interface *intf)
{
	struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);

	if (pdata) {
		cancel_delayed_work(&pdata->carrier_check);
		netif_dbg(dev, ifdown, dev->net, "free pdata\n");
		kfree(pdata);
		pdata = NULL;
		dev->data[0] = 0;
	}
}