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
 int /*<<< orphan*/  CR_CHAN (int /*<<< orphan*/ ) ; 
 unsigned int read_eeprom (struct comedi_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int eeprom_read_insn(struct comedi_device *dev,
			    struct comedi_subdevice *s,
			    struct comedi_insn *insn, unsigned int *data)
{
	unsigned int val;
	unsigned int i;

	if (insn->n) {
		/* No point reading the same EEPROM location more than once. */
		val = read_eeprom(dev, CR_CHAN(insn->chanspec));
		for (i = 0; i < insn->n; i++)
			data[i] = val;
	}

	return insn->n;
}