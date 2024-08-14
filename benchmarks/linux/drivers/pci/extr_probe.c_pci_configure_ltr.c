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
struct pci_host_bridge {int /*<<< orphan*/  native_ltr; } ;
struct pci_dev {int ltr_path; int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 int /*<<< orphan*/  PCI_EXP_DEVCAP2 ; 
 int PCI_EXP_DEVCAP2_LTR ; 
 int /*<<< orphan*/  PCI_EXP_DEVCTL2 ; 
 int PCI_EXP_DEVCTL2_LTR_EN ; 
 scalar_t__ PCI_EXP_TYPE_ROOT_PORT ; 
 struct pci_host_bridge* pci_find_host_bridge (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_is_pcie (struct pci_dev*) ; 
 scalar_t__ pci_pcie_type (struct pci_dev*) ; 
 struct pci_dev* pci_upstream_bridge (struct pci_dev*) ; 
 int /*<<< orphan*/  pcie_capability_read_dword (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pcie_capability_set_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void pci_configure_ltr(struct pci_dev *dev)
{
#ifdef CONFIG_PCIEASPM
	struct pci_host_bridge *host = pci_find_host_bridge(dev->bus);
	struct pci_dev *bridge;
	u32 cap, ctl;

	if (!pci_is_pcie(dev))
		return;

	pcie_capability_read_dword(dev, PCI_EXP_DEVCAP2, &cap);
	if (!(cap & PCI_EXP_DEVCAP2_LTR))
		return;

	pcie_capability_read_dword(dev, PCI_EXP_DEVCTL2, &ctl);
	if (ctl & PCI_EXP_DEVCTL2_LTR_EN) {
		if (pci_pcie_type(dev) == PCI_EXP_TYPE_ROOT_PORT) {
			dev->ltr_path = 1;
			return;
		}

		bridge = pci_upstream_bridge(dev);
		if (bridge && bridge->ltr_path)
			dev->ltr_path = 1;

		return;
	}

	if (!host->native_ltr)
		return;

	/*
	 * Software must not enable LTR in an Endpoint unless the Root
	 * Complex and all intermediate Switches indicate support for LTR.
	 * PCIe r4.0, sec 6.18.
	 */
	if (pci_pcie_type(dev) == PCI_EXP_TYPE_ROOT_PORT ||
	    ((bridge = pci_upstream_bridge(dev)) &&
	      bridge->ltr_path)) {
		pcie_capability_set_word(dev, PCI_EXP_DEVCTL2,
					 PCI_EXP_DEVCTL2_LTR_EN);
		dev->ltr_path = 1;
	}
#endif
}