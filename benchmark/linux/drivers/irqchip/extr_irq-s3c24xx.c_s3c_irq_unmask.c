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
struct s3c_irq_intc {int /*<<< orphan*/  domain; int /*<<< orphan*/  reg_mask; struct s3c_irq_intc* parent; } ;
struct s3c_irq_data {unsigned long offset; int /*<<< orphan*/  parent_irq; struct s3c_irq_intc* intc; } ;
struct irq_data {int dummy; } ;

/* Variables and functions */
 struct s3c_irq_data* irq_data_get_irq_chip_data (struct irq_data*) ; 
 unsigned int irq_find_mapping (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct irq_data* irq_get_irq_data (unsigned int) ; 
 unsigned long readl_relaxed (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void s3c_irq_unmask(struct irq_data *data)
{
	struct s3c_irq_data *irq_data = irq_data_get_irq_chip_data(data);
	struct s3c_irq_intc *intc = irq_data->intc;
	struct s3c_irq_intc *parent_intc = intc->parent;
	unsigned long mask;
	unsigned int irqno;

	mask = readl_relaxed(intc->reg_mask);
	mask &= ~(1UL << irq_data->offset);
	writel_relaxed(mask, intc->reg_mask);

	if (parent_intc) {
		irqno = irq_find_mapping(parent_intc->domain,
					 irq_data->parent_irq);
		s3c_irq_unmask(irq_get_irq_data(irqno));
	}
}