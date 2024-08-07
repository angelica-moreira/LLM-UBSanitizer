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
 int /*<<< orphan*/  i8259a_mask_and_ack_irq (struct irq_data*) ; 

__attribute__((used)) static void
jensen_local_mask_ack(struct irq_data *d)
{
	/* the parport is really hw IRQ 1, silly Jensen.  */
	if (d->irq == 7)
		i8259a_mask_and_ack_irq(d);
}