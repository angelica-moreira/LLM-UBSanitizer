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
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {int dummy; } ;

/* Variables and functions */
 unsigned int CR_CHAN (int /*<<< orphan*/ ) ; 
 unsigned int Z8536_CT_CMDSTAT_GCB ; 
 int /*<<< orphan*/  Z8536_CT_CMDSTAT_REG (unsigned int) ; 
 unsigned int Z8536_CT_CMD_TCB ; 
 unsigned int z8536_read (struct comedi_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  z8536_write (struct comedi_device*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int apci1500_timer_insn_write(struct comedi_device *dev,
				     struct comedi_subdevice *s,
				     struct comedi_insn *insn,
				     unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);
	unsigned int cmd;

	cmd = z8536_read(dev, Z8536_CT_CMDSTAT_REG(chan));
	cmd &= Z8536_CT_CMDSTAT_GCB;	/* preserve gate */
	cmd |= Z8536_CT_CMD_TCB;	/* set trigger */

	/* software trigger a timer, it only makes sense to do one write */
	if (insn->n)
		z8536_write(dev, cmd, Z8536_CT_CMDSTAT_REG(chan));

	return insn->n;
}