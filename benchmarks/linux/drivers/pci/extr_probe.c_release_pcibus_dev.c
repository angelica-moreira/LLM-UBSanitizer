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
struct pci_bus {int /*<<< orphan*/  bridge; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct pci_bus*) ; 
 int /*<<< orphan*/  pci_bus_remove_resources (struct pci_bus*) ; 
 int /*<<< orphan*/  pci_release_bus_of_node (struct pci_bus*) ; 
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ ) ; 
 struct pci_bus* to_pci_bus (struct device*) ; 

__attribute__((used)) static void release_pcibus_dev(struct device *dev)
{
	struct pci_bus *pci_bus = to_pci_bus(dev);

	put_device(pci_bus->bridge);
	pci_bus_remove_resources(pci_bus);
	pci_release_bus_of_node(pci_bus);
	kfree(pci_bus);
}