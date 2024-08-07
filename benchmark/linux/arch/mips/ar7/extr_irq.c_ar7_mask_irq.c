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
 int /*<<< orphan*/  ECR_OFFSET (int) ; 
 int /*<<< orphan*/  REG (int /*<<< orphan*/ ) ; 
 int ar7_irq_base ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ar7_mask_irq(struct irq_data *d)
{
	writel(1 << ((d->irq - ar7_irq_base) % 32),
	       REG(ECR_OFFSET(d->irq - ar7_irq_base)));
}