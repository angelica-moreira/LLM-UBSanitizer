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
struct das1800_private {scalar_t__ iobase2; int /*<<< orphan*/  fifo_buf; } ;
struct comedi_device {struct das1800_private* private; } ;

/* Variables and functions */
 int /*<<< orphan*/  DAS1800_SIZE ; 
 int /*<<< orphan*/  comedi_legacy_detach (struct comedi_device*) ; 
 int /*<<< orphan*/  das1800_free_dma (struct comedi_device*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_region (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void das1800_detach(struct comedi_device *dev)
{
	struct das1800_private *devpriv = dev->private;

	das1800_free_dma(dev);
	if (devpriv) {
		kfree(devpriv->fifo_buf);
		if (devpriv->iobase2)
			release_region(devpriv->iobase2, DAS1800_SIZE);
	}
	comedi_legacy_detach(dev);
}