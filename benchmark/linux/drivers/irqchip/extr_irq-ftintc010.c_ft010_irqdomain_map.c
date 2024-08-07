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
struct irq_domain {struct ft010_irq_data* host_data; } ;
struct ft010_irq_data {int dummy; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int /*<<< orphan*/  ft010_irq_chip ; 
 int /*<<< orphan*/  handle_bad_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct ft010_irq_data*) ; 
 int /*<<< orphan*/  irq_set_probe (unsigned int) ; 

__attribute__((used)) static int ft010_irqdomain_map(struct irq_domain *d, unsigned int irq,
				irq_hw_number_t hwirq)
{
	struct ft010_irq_data *f = d->host_data;

	irq_set_chip_data(irq, f);
	/* All IRQs should set up their type, flags as bad by default */
	irq_set_chip_and_handler(irq, &ft010_irq_chip, handle_bad_irq);
	irq_set_probe(irq);

	return 0;
}