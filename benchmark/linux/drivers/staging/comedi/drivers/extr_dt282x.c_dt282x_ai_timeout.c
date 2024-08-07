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
struct comedi_insn {int dummy; } ;
struct comedi_device {scalar_t__ iobase; } ;

/* Variables and functions */
#define  DT2821_ADCSR_ADDONE 129 
#define  DT2821_ADCSR_MUXBUSY 128 
 scalar_t__ DT2821_ADCSR_REG ; 
 int EBUSY ; 
 int EINVAL ; 
 unsigned int inw (scalar_t__) ; 

__attribute__((used)) static int dt282x_ai_timeout(struct comedi_device *dev,
			     struct comedi_subdevice *s,
			     struct comedi_insn *insn,
			     unsigned long context)
{
	unsigned int status;

	status = inw(dev->iobase + DT2821_ADCSR_REG);
	switch (context) {
	case DT2821_ADCSR_MUXBUSY:
		if ((status & DT2821_ADCSR_MUXBUSY) == 0)
			return 0;
		break;
	case DT2821_ADCSR_ADDONE:
		if (status & DT2821_ADCSR_ADDONE)
			return 0;
		break;
	default:
		return -EINVAL;
	}
	return -EBUSY;
}