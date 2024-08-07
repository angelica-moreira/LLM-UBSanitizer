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
struct comedi_subdevice {int dummy; } ;
struct comedi_insn {int n; } ;
struct comedi_device {scalar_t__ iobase; } ;

/* Variables and functions */
 scalar_t__ PCL812_DI_LSB_REG ; 
 scalar_t__ PCL812_DI_MSB_REG ; 
 int inb (scalar_t__) ; 

__attribute__((used)) static int pcl812_di_insn_bits(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       struct comedi_insn *insn,
			       unsigned int *data)
{
	data[1] = inb(dev->iobase + PCL812_DI_LSB_REG) |
		  (inb(dev->iobase + PCL812_DI_MSB_REG) << 8);

	return insn->n;
}