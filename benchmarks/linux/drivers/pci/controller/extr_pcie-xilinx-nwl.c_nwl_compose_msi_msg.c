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
struct nwl_pcie {int /*<<< orphan*/  phys_pcie_reg_base; } ;
struct msi_msg {int /*<<< orphan*/  data; int /*<<< orphan*/  address_hi; int /*<<< orphan*/  address_lo; } ;
struct irq_data {int /*<<< orphan*/  hwirq; } ;
typedef  int /*<<< orphan*/  phys_addr_t ;

/* Variables and functions */
 struct nwl_pcie* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int /*<<< orphan*/  lower_32_bits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  upper_32_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nwl_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
	struct nwl_pcie *pcie = irq_data_get_irq_chip_data(data);
	phys_addr_t msi_addr = pcie->phys_pcie_reg_base;

	msg->address_lo = lower_32_bits(msi_addr);
	msg->address_hi = upper_32_bits(msi_addr);
	msg->data = data->hwirq;
}