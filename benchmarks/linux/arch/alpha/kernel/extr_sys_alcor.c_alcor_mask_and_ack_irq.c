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
typedef  int* vuip ;
struct irq_data {int irq; } ;

/* Variables and functions */
 scalar_t__ GRU_INT_CLEAR ; 
 int /*<<< orphan*/  alcor_disable_irq (struct irq_data*) ; 
 int /*<<< orphan*/  mb () ; 

__attribute__((used)) static void
alcor_mask_and_ack_irq(struct irq_data *d)
{
	alcor_disable_irq(d);

	/* On ALCOR/XLT, need to dismiss interrupt via GRU. */
	*(vuip)GRU_INT_CLEAR = 1 << (d->irq - 16); mb();
	*(vuip)GRU_INT_CLEAR = 0; mb();
}