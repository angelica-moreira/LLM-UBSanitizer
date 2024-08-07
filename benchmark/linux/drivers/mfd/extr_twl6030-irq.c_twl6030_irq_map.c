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
struct twl6030_irq {int /*<<< orphan*/  twl_irq; int /*<<< orphan*/  irq_chip; } ;
struct irq_domain {struct twl6030_irq* host_data; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int /*<<< orphan*/  handle_simple_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct twl6030_irq*) ; 
 int /*<<< orphan*/  irq_set_nested_thread (unsigned int,int) ; 
 int /*<<< orphan*/  irq_set_noprobe (unsigned int) ; 
 int /*<<< orphan*/  irq_set_parent (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int twl6030_irq_map(struct irq_domain *d, unsigned int virq,
			      irq_hw_number_t hwirq)
{
	struct twl6030_irq *pdata = d->host_data;

	irq_set_chip_data(virq, pdata);
	irq_set_chip_and_handler(virq,  &pdata->irq_chip, handle_simple_irq);
	irq_set_nested_thread(virq, true);
	irq_set_parent(virq, pdata->twl_irq);
	irq_set_noprobe(virq);

	return 0;
}