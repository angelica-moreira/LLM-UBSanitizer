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
struct usb_interface {int sysfs_files_created; int /*<<< orphan*/  dev; scalar_t__ unregistering; struct usb_host_interface* cur_altsetting; } ;
struct TYPE_2__ {int /*<<< orphan*/  iInterface; } ;
struct usb_host_interface {scalar_t__ string; TYPE_1__ desc; } ;
struct usb_device {int quirks; } ;

/* Variables and functions */
 int USB_QUIRK_CONFIG_INTF_STRINGS ; 
 int /*<<< orphan*/  dev_attr_interface ; 
 scalar_t__ device_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 scalar_t__ usb_cache_string (struct usb_device*,int /*<<< orphan*/ ) ; 

void usb_create_sysfs_intf_files(struct usb_interface *intf)
{
	struct usb_device *udev = interface_to_usbdev(intf);
	struct usb_host_interface *alt = intf->cur_altsetting;

	if (intf->sysfs_files_created || intf->unregistering)
		return;

	if (!alt->string && !(udev->quirks & USB_QUIRK_CONFIG_INTF_STRINGS))
		alt->string = usb_cache_string(udev, alt->desc.iInterface);
	if (alt->string && device_create_file(&intf->dev, &dev_attr_interface))
		;	/* We don't actually care if the function fails. */
	intf->sysfs_files_created = 1;
}