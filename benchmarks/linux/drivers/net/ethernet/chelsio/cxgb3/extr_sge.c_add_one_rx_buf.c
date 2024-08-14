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
typedef  int u64 ;
struct rx_sw_desc {int dummy; } ;
struct rx_desc {void* gen2; void* len_gen; void* addr_hi; void* addr_lo; } ;
struct pci_dev {int dummy; } ;
typedef  int dma_addr_t ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  PCI_DMA_FROMDEVICE ; 
 int V_FLD_GEN1 (unsigned int) ; 
 int V_FLD_GEN2 (unsigned int) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  dma_addr ; 
 int /*<<< orphan*/  dma_unmap_addr_set (struct rx_sw_desc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dma_wmb () ; 
 int /*<<< orphan*/  pci_dma_mapping_error (struct pci_dev*,int) ; 
 int pci_map_single (struct pci_dev*,void*,unsigned int,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int add_one_rx_buf(void *va, unsigned int len,
				 struct rx_desc *d, struct rx_sw_desc *sd,
				 unsigned int gen, struct pci_dev *pdev)
{
	dma_addr_t mapping;

	mapping = pci_map_single(pdev, va, len, PCI_DMA_FROMDEVICE);
	if (unlikely(pci_dma_mapping_error(pdev, mapping)))
		return -ENOMEM;

	dma_unmap_addr_set(sd, dma_addr, mapping);

	d->addr_lo = cpu_to_be32(mapping);
	d->addr_hi = cpu_to_be32((u64) mapping >> 32);
	dma_wmb();
	d->len_gen = cpu_to_be32(V_FLD_GEN1(gen));
	d->gen2 = cpu_to_be32(V_FLD_GEN2(gen));
	return 0;
}