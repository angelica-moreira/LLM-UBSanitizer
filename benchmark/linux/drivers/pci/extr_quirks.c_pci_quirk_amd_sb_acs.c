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
typedef  int u16 ;
struct pci_dev {int /*<<< orphan*/  bus; int /*<<< orphan*/  multifunction; } ;
struct acpi_table_header {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int PCI_ACS_CR ; 
 int PCI_ACS_DT ; 
 int PCI_ACS_EC ; 
 int PCI_ACS_RR ; 
 int /*<<< orphan*/  acpi_get_table (char*,int /*<<< orphan*/ ,struct acpi_table_header**) ; 
 int /*<<< orphan*/  pci_is_root_bus (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int pci_quirk_amd_sb_acs(struct pci_dev *dev, u16 acs_flags)
{
#ifdef CONFIG_ACPI
	struct acpi_table_header *header = NULL;
	acpi_status status;

	/* Targeting multifunction devices on the SB (appears on root bus) */
	if (!dev->multifunction || !pci_is_root_bus(dev->bus))
		return -ENODEV;

	/* The IVRS table describes the AMD IOMMU */
	status = acpi_get_table("IVRS", 0, &header);
	if (ACPI_FAILURE(status))
		return -ENODEV;

	/* Filter out flags not applicable to multifunction */
	acs_flags &= (PCI_ACS_RR | PCI_ACS_CR | PCI_ACS_EC | PCI_ACS_DT);

	return acs_flags & ~(PCI_ACS_RR | PCI_ACS_CR) ? 0 : 1;
#else
	return -ENODEV;
#endif
}