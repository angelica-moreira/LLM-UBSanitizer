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
struct usbduxsigma_private {scalar_t__ ai_cmd_running; int /*<<< orphan*/  n_ai_urbs; scalar_t__ ai_urbs; } ;
struct comedi_device {struct usbduxsigma_private* private; } ;

/* Variables and functions */
 int /*<<< orphan*/  usbduxsigma_unlink_urbs (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void usbduxsigma_ai_stop(struct comedi_device *dev, int do_unlink)
{
	struct usbduxsigma_private *devpriv = dev->private;

	if (do_unlink && devpriv->ai_urbs)
		usbduxsigma_unlink_urbs(devpriv->ai_urbs, devpriv->n_ai_urbs);

	devpriv->ai_cmd_running = 0;
}