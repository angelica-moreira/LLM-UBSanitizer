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
struct irq_data {int irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  BALLOON3_INT_CONTROL_REG ; 
 int BALLOON3_IRQ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ ) ; 
 int balloon3_irq_enabled ; 

__attribute__((used)) static void balloon3_mask_irq(struct irq_data *d)
{
	int balloon3_irq = (d->irq - BALLOON3_IRQ(0));
	balloon3_irq_enabled &= ~(1 << balloon3_irq);
	__raw_writel(~balloon3_irq_enabled, BALLOON3_INT_CONTROL_REG);
}