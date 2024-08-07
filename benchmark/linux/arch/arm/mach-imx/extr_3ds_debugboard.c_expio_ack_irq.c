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
typedef  int u32 ;
struct irq_data {int hwirq; } ;

/* Variables and functions */
 scalar_t__ INTR_RESET_REG ; 
 scalar_t__ brd_io ; 
 int /*<<< orphan*/  expio_mask_irq (struct irq_data*) ; 
 int /*<<< orphan*/  imx_writew (int,scalar_t__) ; 

__attribute__((used)) static void expio_ack_irq(struct irq_data *d)
{
	u32 expio = d->hwirq;

	imx_writew(1 << expio, brd_io + INTR_RESET_REG);
	imx_writew(0, brd_io + INTR_RESET_REG);
	expio_mask_irq(d);
}