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
struct usbduxsigma_private {int ai_cmd_running; int /*<<< orphan*/  mut; int /*<<< orphan*/  n_ai_urbs; int /*<<< orphan*/  ai_urbs; } ;
struct comedi_subdevice {TYPE_1__* async; } ;
struct comedi_device {struct usbduxsigma_private* private; } ;
struct comedi_cmd {unsigned int start_arg; } ;
struct TYPE_2__ {int /*<<< orphan*/ * inttrig; struct comedi_cmd cmd; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int usbduxsigma_submit_urbs (struct comedi_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int usbduxsigma_ai_inttrig(struct comedi_device *dev,
				  struct comedi_subdevice *s,
				  unsigned int trig_num)
{
	struct usbduxsigma_private *devpriv = dev->private;
	struct comedi_cmd *cmd = &s->async->cmd;
	int ret;

	if (trig_num != cmd->start_arg)
		return -EINVAL;

	mutex_lock(&devpriv->mut);
	if (!devpriv->ai_cmd_running) {
		devpriv->ai_cmd_running = 1;
		ret = usbduxsigma_submit_urbs(dev, devpriv->ai_urbs,
					      devpriv->n_ai_urbs, 1);
		if (ret < 0) {
			devpriv->ai_cmd_running = 0;
			mutex_unlock(&devpriv->mut);
			return ret;
		}
		s->async->inttrig = NULL;
	}
	mutex_unlock(&devpriv->mut);

	return 1;
}