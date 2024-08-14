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
struct irq_data {int hwirq; } ;
struct ab8500 {int* mask; } ;

/* Variables and functions */
 int AB8500_INT_GPIO41R ; 
 int AB8500_INT_GPIO6R ; 
 int AB8540_INT_GPIO43R ; 
 int AB8540_INT_GPIO44R ; 
 int AB9540_INT_GPIO50R ; 
 int AB9540_INT_GPIO54R ; 
 struct ab8500* irq_data_get_irq_chip_data (struct irq_data*) ; 

__attribute__((used)) static void ab8500_irq_mask(struct irq_data *data)
{
	struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
	int offset = data->hwirq;
	int index = offset / 8;
	int mask = 1 << (offset % 8);

	ab8500->mask[index] |= mask;

	/* The AB8500 GPIOs have two interrupts each (rising & falling). */
	if (offset >= AB8500_INT_GPIO6R && offset <= AB8500_INT_GPIO41R)
		ab8500->mask[index + 2] |= mask;
	if (offset >= AB9540_INT_GPIO50R && offset <= AB9540_INT_GPIO54R)
		ab8500->mask[index + 1] |= mask;
	if (offset == AB8540_INT_GPIO43R || offset == AB8540_INT_GPIO44R)
		/* Here the falling IRQ is one bit lower */
		ab8500->mask[index] |= (mask << 1);
}