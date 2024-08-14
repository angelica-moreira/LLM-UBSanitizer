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
struct pcmcia_device {struct comedi_device* priv; } ;
struct daqp_private {int stop; } ;
struct comedi_device {struct daqp_private* private; } ;

/* Variables and functions */

__attribute__((used)) static int daqp_cs_suspend(struct pcmcia_device *link)
{
	struct comedi_device *dev = link->priv;
	struct daqp_private *devpriv = dev ? dev->private : NULL;

	/* Mark the device as stopped, to block IO until later */
	if (devpriv)
		devpriv->stop = 1;

	return 0;
}