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
 int /*<<< orphan*/  msi_set_mask_bit (struct irq_data*,int /*<<< orphan*/ ) ; 

void pci_msi_unmask_irq(struct irq_data *data)
{
	msi_set_mask_bit(data, 0);
}