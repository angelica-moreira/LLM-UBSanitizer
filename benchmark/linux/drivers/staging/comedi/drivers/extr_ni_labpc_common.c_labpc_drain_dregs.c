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
struct labpc_private {scalar_t__ current_transfer; } ;
struct comedi_device {struct labpc_private* private; } ;

/* Variables and functions */
 scalar_t__ isa_dma_transfer ; 
 int /*<<< orphan*/  labpc_drain_dma (struct comedi_device*) ; 
 int /*<<< orphan*/  labpc_drain_fifo (struct comedi_device*) ; 

__attribute__((used)) static void labpc_drain_dregs(struct comedi_device *dev)
{
	struct labpc_private *devpriv = dev->private;

	if (devpriv->current_transfer == isa_dma_transfer)
		labpc_drain_dma(dev);

	labpc_drain_fifo(dev);
}