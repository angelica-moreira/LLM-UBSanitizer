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
struct irq_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fpga_ack_irq (struct irq_data*) ; 
 int /*<<< orphan*/  fpga_mask_irq (struct irq_data*) ; 

__attribute__((used)) static void fpga_mask_ack_irq(struct irq_data *d)
{
	fpga_mask_irq(d);
	fpga_ack_irq(d);
}