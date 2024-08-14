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
struct usb_host_endpoint {int streams; int /*<<< orphan*/  desc; } ;
struct usb_hcd {TYPE_1__* driver; } ;
struct usb_device {scalar_t__ speed; scalar_t__ state; int /*<<< orphan*/  bus; } ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_2__ {int (* alloc_streams ) (struct usb_hcd*,struct usb_device*,struct usb_host_endpoint**,unsigned int,unsigned int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  free_streams; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ USB_SPEED_SUPER ; 
 scalar_t__ USB_STATE_CONFIGURED ; 
 struct usb_hcd* bus_to_hcd (int /*<<< orphan*/ ) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int stub1 (struct usb_hcd*,struct usb_device*,struct usb_host_endpoint**,unsigned int,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_endpoint_xfer_bulk (int /*<<< orphan*/ *) ; 

int usb_alloc_streams(struct usb_interface *interface,
		struct usb_host_endpoint **eps, unsigned int num_eps,
		unsigned int num_streams, gfp_t mem_flags)
{
	struct usb_hcd *hcd;
	struct usb_device *dev;
	int i, ret;

	dev = interface_to_usbdev(interface);
	hcd = bus_to_hcd(dev->bus);
	if (!hcd->driver->alloc_streams || !hcd->driver->free_streams)
		return -EINVAL;
	if (dev->speed < USB_SPEED_SUPER)
		return -EINVAL;
	if (dev->state < USB_STATE_CONFIGURED)
		return -ENODEV;

	for (i = 0; i < num_eps; i++) {
		/* Streams only apply to bulk endpoints. */
		if (!usb_endpoint_xfer_bulk(&eps[i]->desc))
			return -EINVAL;
		/* Re-alloc is not allowed */
		if (eps[i]->streams)
			return -EINVAL;
	}

	ret = hcd->driver->alloc_streams(hcd, dev, eps, num_eps,
			num_streams, mem_flags);
	if (ret < 0)
		return ret;

	for (i = 0; i < num_eps; i++)
		eps[i]->streams = ret;

	return ret;
}