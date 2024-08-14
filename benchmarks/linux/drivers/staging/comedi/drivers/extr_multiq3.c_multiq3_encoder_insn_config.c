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
 int EINVAL ; 
#define  INSN_CONFIG_RESET 128 
 int /*<<< orphan*/  multiq3_encoder_reset (struct comedi_device*,unsigned int) ; 

__attribute__((used)) static int multiq3_encoder_insn_config(struct comedi_device *dev,
				       struct comedi_subdevice *s,
				       struct comedi_insn *insn,
				       unsigned int *data)
{
	unsigned int chan = CR_CHAN(insn->chanspec);

	switch (data[0]) {
	case INSN_CONFIG_RESET:
		multiq3_encoder_reset(dev, chan);
		break;
	default:
		return -EINVAL;
	}

	return insn->n;
}