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
struct pci_dev {int /*<<< orphan*/  bus; } ;
struct pci_controller {int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  cxl_pcie_pci_ops ; 
 struct pci_controller* pci_bus_to_host (int /*<<< orphan*/ ) ; 

bool cxl_pci_is_vphb_device(struct pci_dev *dev)
{
	struct pci_controller *phb;

	phb = pci_bus_to_host(dev->bus);

	return (phb->ops == &cxl_pcie_pci_ops);
}