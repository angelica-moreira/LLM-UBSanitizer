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
struct usb_host_endpoint {scalar_t__ streams; } ;
struct usb_hcd {TYPE_1__* driver; } ;
struct usb_device {scalar_t__ speed; int /*<<< orphan*/  bus; } ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_2__ {int (* free_streams ) (struct usb_hcd*,struct usb_device*,struct usb_host_endpoint**,unsigned int,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ USB_SPEED_SUPER ; 
 struct usb_hcd* bus_to_hcd (int /*<<< orphan*/ ) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int stub1 (struct usb_hcd*,struct usb_device*,struct usb_host_endpoint**,unsigned int,int /*<<< orphan*/ ) ; 

int usb_free_streams(struct usb_interface *interface,
		struct usb_host_endpoint **eps, unsigned int num_eps,
		gfp_t mem_flags)
{
	struct usb_hcd *hcd;
	struct usb_device *dev;
	int i, ret;

	dev = interface_to_usbdev(interface);
	hcd = bus_to_hcd(dev->bus);
	if (dev->speed < USB_SPEED_SUPER)
		return -EINVAL;

	/* Double-free is not allowed */
	for (i = 0; i < num_eps; i++)
		if (!eps[i] || !eps[i]->streams)
			return -EINVAL;

	ret = hcd->driver->free_streams(hcd, dev, eps, num_eps, mem_flags);
	if (ret < 0)
		return ret;

	for (i = 0; i < num_eps; i++)
		eps[i]->streams = 0;

	return ret;
}