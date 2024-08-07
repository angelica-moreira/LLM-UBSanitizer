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
struct usb_device {int dummy; } ;
struct kbtab {TYPE_1__* irq; int /*<<< orphan*/  intf; } ;
struct input_dev {int dummy; } ;
struct TYPE_2__ {struct usb_device* dev; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct kbtab* input_get_drvdata (struct input_dev*) ; 
 struct usb_device* interface_to_usbdev (int /*<<< orphan*/ ) ; 
 scalar_t__ usb_submit_urb (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int kbtab_open(struct input_dev *dev)
{
	struct kbtab *kbtab = input_get_drvdata(dev);
	struct usb_device *udev = interface_to_usbdev(kbtab->intf);

	kbtab->irq->dev = udev;
	if (usb_submit_urb(kbtab->irq, GFP_KERNEL))
		return -EIO;

	return 0;
}