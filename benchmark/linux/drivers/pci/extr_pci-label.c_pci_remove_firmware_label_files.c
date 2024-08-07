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
struct pci_dev {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ device_has_dsm (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_remove_acpi_index_label_files (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_remove_smbiosname_file (struct pci_dev*) ; 

void pci_remove_firmware_label_files(struct pci_dev *pdev)
{
	if (device_has_dsm(&pdev->dev))
		pci_remove_acpi_index_label_files(pdev);
	else
		pci_remove_smbiosname_file(pdev);
}