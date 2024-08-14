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

/* Variables and functions */
 int /*<<< orphan*/  DAVINCI_CP_INTC_HOST_ENABLE_IDX_CLR ; 
 int /*<<< orphan*/  DAVINCI_CP_INTC_HOST_ENABLE_IDX_SET ; 
 int /*<<< orphan*/  DAVINCI_CP_INTC_SYS_ENABLE_IDX_CLR ; 
 int /*<<< orphan*/  davinci_cp_intc_write (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void davinci_cp_intc_mask_irq(struct irq_data *d)
{
	/* XXX don't know why we need to disable nIRQ here... */
	davinci_cp_intc_write(1, DAVINCI_CP_INTC_HOST_ENABLE_IDX_CLR);
	davinci_cp_intc_write(d->hwirq, DAVINCI_CP_INTC_SYS_ENABLE_IDX_CLR);
	davinci_cp_intc_write(1, DAVINCI_CP_INTC_HOST_ENABLE_IDX_SET);
}