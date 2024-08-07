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
struct device {int dummy; } ;
struct pci_dev {struct device dev; } ;
struct netxen_adapter {struct pci_dev* pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  bin_attr_crb ; 
 int /*<<< orphan*/  bin_attr_dimm ; 
 int /*<<< orphan*/  bin_attr_mem ; 
 int /*<<< orphan*/  dev_attr_diag_mode ; 
 int /*<<< orphan*/  device_remove_bin_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (struct device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
netxen_remove_diag_entries(struct netxen_adapter *adapter)
{
	struct pci_dev *pdev = adapter->pdev;
	struct device *dev = &pdev->dev;

	device_remove_file(dev, &dev_attr_diag_mode);
	device_remove_bin_file(dev, &bin_attr_crb);
	device_remove_bin_file(dev, &bin_attr_mem);
	device_remove_bin_file(dev, &bin_attr_dimm);
}