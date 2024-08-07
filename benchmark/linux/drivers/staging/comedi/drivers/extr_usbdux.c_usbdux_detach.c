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
struct usbdux_private {int /*<<< orphan*/  mut; } ;
struct usb_interface {int dummy; } ;
struct comedi_device {struct usbdux_private* private; } ;

/* Variables and functions */
 struct usb_interface* comedi_to_usb_interface (struct comedi_device*) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_set_intfdata (struct usb_interface*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usbdux_ai_stop (struct comedi_device*,int) ; 
 int /*<<< orphan*/  usbdux_ao_stop (struct comedi_device*,int) ; 
 int /*<<< orphan*/  usbdux_free_usb_buffers (struct comedi_device*) ; 
 int /*<<< orphan*/  usbdux_pwm_stop (struct comedi_device*,int) ; 

__attribute__((used)) static void usbdux_detach(struct comedi_device *dev)
{
	struct usb_interface *intf = comedi_to_usb_interface(dev);
	struct usbdux_private *devpriv = dev->private;

	usb_set_intfdata(intf, NULL);

	if (!devpriv)
		return;

	mutex_lock(&devpriv->mut);

	/* force unlink all urbs */
	usbdux_pwm_stop(dev, 1);
	usbdux_ao_stop(dev, 1);
	usbdux_ai_stop(dev, 1);

	usbdux_free_usb_buffers(dev);

	mutex_unlock(&devpriv->mut);

	mutex_destroy(&devpriv->mut);
}