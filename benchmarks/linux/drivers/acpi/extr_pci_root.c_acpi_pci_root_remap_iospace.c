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
struct resource_entry {void* offset; struct resource* res; } ;
struct resource {unsigned long start; int /*<<< orphan*/  flags; void* end; } ;
struct fwnode_handle {int dummy; } ;
typedef  void* resource_size_t ;

/* Variables and functions */
 int /*<<< orphan*/  IORESOURCE_DISABLED ; 
 unsigned long pci_address_to_pio (void*) ; 
 scalar_t__ pci_register_io_range (struct fwnode_handle*,void*,void*) ; 
 scalar_t__ pci_remap_iospace (struct resource*,void*) ; 
 int /*<<< orphan*/  pr_info (char*,void**,struct resource*) ; 
 void* resource_size (struct resource*) ; 

__attribute__((used)) static void acpi_pci_root_remap_iospace(struct fwnode_handle *fwnode,
			struct resource_entry *entry)
{
#ifdef PCI_IOBASE
	struct resource *res = entry->res;
	resource_size_t cpu_addr = res->start;
	resource_size_t pci_addr = cpu_addr - entry->offset;
	resource_size_t length = resource_size(res);
	unsigned long port;

	if (pci_register_io_range(fwnode, cpu_addr, length))
		goto err;

	port = pci_address_to_pio(cpu_addr);
	if (port == (unsigned long)-1)
		goto err;

	res->start = port;
	res->end = port + length - 1;
	entry->offset = port - pci_addr;

	if (pci_remap_iospace(res, cpu_addr) < 0)
		goto err;

	pr_info("Remapped I/O %pa to %pR\n", &cpu_addr, res);
	return;
err:
	res->flags |= IORESOURCE_DISABLED;
#endif
}