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
struct comedi_device {int /*<<< orphan*/  iobase; } ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int EBUSY ; 
 unsigned int inw_p (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dyna_pci10xx_ai_eoc(struct comedi_device *dev,
			       struct comedi_subdevice *s,
			       struct comedi_insn *insn,
			       unsigned long context)
{
	unsigned int status;

	status = inw_p(dev->iobase);
	if (status & BIT(15))
		return 0;
	return -EBUSY;
}