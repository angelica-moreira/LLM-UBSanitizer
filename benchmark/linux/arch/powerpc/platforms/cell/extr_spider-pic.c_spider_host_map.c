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
struct irq_domain {int /*<<< orphan*/  host_data; } ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_TYPE_NONE ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_irq_type (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spider_pic ; 

__attribute__((used)) static int spider_host_map(struct irq_domain *h, unsigned int virq,
			irq_hw_number_t hw)
{
	irq_set_chip_data(virq, h->host_data);
	irq_set_chip_and_handler(virq, &spider_pic, handle_level_irq);

	/* Set default irq type */
	irq_set_irq_type(virq, IRQ_TYPE_NONE);

	return 0;
}