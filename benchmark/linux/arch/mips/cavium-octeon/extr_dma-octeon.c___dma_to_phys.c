#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  phys_addr_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* dma_to_phys ) (struct device*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 scalar_t__ dev_is_pci (struct device*) ; 
 TYPE_1__* octeon_pci_dma_ops ; 
 int /*<<< orphan*/  stub1 (struct device*,int /*<<< orphan*/ ) ; 

phys_addr_t __dma_to_phys(struct device *dev, dma_addr_t daddr)
{
#ifdef CONFIG_PCI
	if (dev && dev_is_pci(dev))
		return octeon_pci_dma_ops->dma_to_phys(dev, daddr);
#endif
	return daddr;
}