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
struct comedi_device {scalar_t__ mmio; } ;

/* Variables and functions */
 int /*<<< orphan*/  NI6527_CTRL_DISABLE_IRQS ; 
 scalar_t__ NI6527_CTRL_REG ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int ni6527_intr_cancel(struct comedi_device *dev,
			      struct comedi_subdevice *s)
{
	writeb(NI6527_CTRL_DISABLE_IRQS, dev->mmio + NI6527_CTRL_REG);

	return 0;
}