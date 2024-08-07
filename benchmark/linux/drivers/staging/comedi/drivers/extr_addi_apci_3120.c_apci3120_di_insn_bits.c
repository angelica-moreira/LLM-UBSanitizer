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
 scalar_t__ APCI3120_STATUS_REG ; 
 unsigned int APCI3120_STATUS_TO_DI_BITS (unsigned int) ; 
 unsigned int inw (scalar_t__) ; 

__attribute__((used)) static int apci3120_di_insn_bits(struct comedi_device *dev,
				 struct comedi_subdevice *s,
				 struct comedi_insn *insn,
				 unsigned int *data)
{
	unsigned int status;

	status = inw(dev->iobase + APCI3120_STATUS_REG);
	data[1] = APCI3120_STATUS_TO_DI_BITS(status);

	return insn->n;
}