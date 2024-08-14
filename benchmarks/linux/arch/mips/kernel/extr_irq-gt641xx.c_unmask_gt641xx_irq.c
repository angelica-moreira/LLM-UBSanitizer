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
typedef  int /*<<< orphan*/  u32 ;
struct irq_data {int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  GT641XX_IRQ_TO_BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GT_INTRMASK_OFS ; 
 int /*<<< orphan*/  GT_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GT_WRITE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gt641xx_irq_lock ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void unmask_gt641xx_irq(struct irq_data *d)
{
	unsigned long flags;
	u32 mask;

	raw_spin_lock_irqsave(&gt641xx_irq_lock, flags);
	mask = GT_READ(GT_INTRMASK_OFS);
	mask |= GT641XX_IRQ_TO_BIT(d->irq);
	GT_WRITE(GT_INTRMASK_OFS, mask);
	raw_spin_unlock_irqrestore(&gt641xx_irq_lock, flags);
}