#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  masked; } ;
struct moxtet {TYPE_1__ irq; } ;
struct irq_data {int /*<<< orphan*/  hwirq; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 struct moxtet* irq_data_get_irq_chip_data (struct irq_data*) ; 

__attribute__((used)) static void moxtet_irq_mask(struct irq_data *d)
{
	struct moxtet *moxtet = irq_data_get_irq_chip_data(d);

	moxtet->irq.masked |= BIT(d->hwirq);
}