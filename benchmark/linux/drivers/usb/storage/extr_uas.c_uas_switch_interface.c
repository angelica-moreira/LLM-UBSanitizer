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
struct usb_interface {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  bAlternateSetting; int /*<<< orphan*/  bInterfaceNumber; } ;
struct usb_host_interface {TYPE_1__ desc; } ;
struct usb_device {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 struct usb_host_interface* uas_find_uas_alt_setting (struct usb_interface*) ; 
 int usb_set_interface (struct usb_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int uas_switch_interface(struct usb_device *udev,
				struct usb_interface *intf)
{
	struct usb_host_interface *alt;

	alt = uas_find_uas_alt_setting(intf);
	if (!alt)
		return -ENODEV;

	return usb_set_interface(udev, alt->desc.bInterfaceNumber,
			alt->desc.bAlternateSetting);
}