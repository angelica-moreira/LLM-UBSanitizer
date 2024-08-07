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
typedef  int u32 ;
struct uic {int /*<<< orphan*/  lock; scalar_t__ dcrbase; } ;
struct irq_data {int dummy; } ;

/* Variables and functions */
 scalar_t__ UIC_ER ; 
 scalar_t__ UIC_SR ; 
 struct uic* irq_data_get_irq_chip_data (struct irq_data*) ; 
 scalar_t__ irqd_is_level_type (struct irq_data*) ; 
 unsigned int irqd_to_hwirq (struct irq_data*) ; 
 int mfdcr (scalar_t__) ; 
 int /*<<< orphan*/  mtdcr (scalar_t__,int) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void uic_unmask_irq(struct irq_data *d)
{
	struct uic *uic = irq_data_get_irq_chip_data(d);
	unsigned int src = irqd_to_hwirq(d);
	unsigned long flags;
	u32 er, sr;

	sr = 1 << (31-src);
	raw_spin_lock_irqsave(&uic->lock, flags);
	/* ack level-triggered interrupts here */
	if (irqd_is_level_type(d))
		mtdcr(uic->dcrbase + UIC_SR, sr);
	er = mfdcr(uic->dcrbase + UIC_ER);
	er |= sr;
	mtdcr(uic->dcrbase + UIC_ER, er);
	raw_spin_unlock_irqrestore(&uic->lock, flags);
}