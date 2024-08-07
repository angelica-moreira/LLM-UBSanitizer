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
struct usbdux_private {int /*<<< orphan*/  mut; int /*<<< orphan*/  ai_cmd_running; } ;
struct comedi_subdevice {int dummy; } ;
struct comedi_device {struct usbdux_private* private; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usbdux_ai_stop (struct comedi_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int usbdux_ai_cancel(struct comedi_device *dev,
			    struct comedi_subdevice *s)
{
	struct usbdux_private *devpriv = dev->private;

	/* prevent other CPUs from submitting new commands just now */
	mutex_lock(&devpriv->mut);
	/* unlink only if the urb really has been submitted */
	usbdux_ai_stop(dev, devpriv->ai_cmd_running);
	mutex_unlock(&devpriv->mut);

	return 0;
}