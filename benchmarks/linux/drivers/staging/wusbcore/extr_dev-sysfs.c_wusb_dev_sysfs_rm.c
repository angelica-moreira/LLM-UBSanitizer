#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct wusb_dev {struct usb_device* usb_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  kobj; } ;
struct usb_device {TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wusb_dev_attr_group ; 

void wusb_dev_sysfs_rm(struct wusb_dev *wusb_dev)
{
	struct usb_device *usb_dev = wusb_dev->usb_dev;
	if (usb_dev)
		sysfs_remove_group(&usb_dev->dev.kobj, &wusb_dev_attr_group);
}