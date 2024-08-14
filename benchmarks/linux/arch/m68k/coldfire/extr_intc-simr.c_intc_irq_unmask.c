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
struct irq_data {unsigned int irq; } ;

/* Variables and functions */
 scalar_t__ MCFINTC0_CIMR ; 
 scalar_t__ MCFINTC1_CIMR ; 
 scalar_t__ MCFINTC2_CIMR ; 
 unsigned int MCFINT_VECBASE ; 
 int /*<<< orphan*/  __raw_writeb (unsigned int,scalar_t__) ; 

__attribute__((used)) static void intc_irq_unmask(struct irq_data *d)
{
	unsigned int irq = d->irq - MCFINT_VECBASE;

	if (MCFINTC2_CIMR && (irq > 128))
		__raw_writeb(irq - 128, MCFINTC2_CIMR);
	else if (MCFINTC1_CIMR && (irq > 64))
		__raw_writeb(irq - 64, MCFINTC1_CIMR);
	else
		__raw_writeb(irq, MCFINTC0_CIMR);
}