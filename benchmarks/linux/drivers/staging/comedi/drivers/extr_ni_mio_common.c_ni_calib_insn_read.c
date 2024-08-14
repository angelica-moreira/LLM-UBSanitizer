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
struct ni_private {unsigned int* caldacs; } ;
struct comedi_subdevice {int dummy; } ;
struct comedi_insn {unsigned int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {struct ni_private* private; } ;

/* Variables and functions */
 size_t CR_CHAN (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ni_calib_insn_read(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_insn *insn,
			      unsigned int *data)
{
	struct ni_private *devpriv = dev->private;
	unsigned int i;

	for (i = 0; i < insn->n; i++)
		data[0] = devpriv->caldacs[CR_CHAN(insn->chanspec)];

	return insn->n;
}