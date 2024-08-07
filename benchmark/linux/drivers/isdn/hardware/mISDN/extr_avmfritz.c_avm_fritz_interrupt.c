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
typedef  int u8 ;
struct fritzcard {int /*<<< orphan*/  lock; int /*<<< orphan*/  isac; int /*<<< orphan*/  irqcnt; int /*<<< orphan*/  name; scalar_t__ addr; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int AVM_STATUS0_IRQ_HDLC ; 
 int AVM_STATUS0_IRQ_ISAC ; 
 int AVM_STATUS0_IRQ_MASK ; 
 int /*<<< orphan*/  HDLC_irq_main (struct fritzcard*) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  ISAC_ISTA ; 
 int ReadISAC_V1 (struct fritzcard*,int /*<<< orphan*/ ) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  mISDNisac_irq (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t
avm_fritz_interrupt(int intno, void *dev_id)
{
	struct fritzcard *fc = dev_id;
	u8 val;
	u8 sval;

	spin_lock(&fc->lock);
	sval = inb(fc->addr + 2);
	pr_debug("%s: irq stat0 %x\n", fc->name, sval);
	if ((sval & AVM_STATUS0_IRQ_MASK) == AVM_STATUS0_IRQ_MASK) {
		/* shared  IRQ from other HW */
		spin_unlock(&fc->lock);
		return IRQ_NONE;
	}
	fc->irqcnt++;

	if (!(sval & AVM_STATUS0_IRQ_ISAC)) {
		val = ReadISAC_V1(fc, ISAC_ISTA);
		mISDNisac_irq(&fc->isac, val);
	}
	if (!(sval & AVM_STATUS0_IRQ_HDLC))
		HDLC_irq_main(fc);
	spin_unlock(&fc->lock);
	return IRQ_HANDLED;
}