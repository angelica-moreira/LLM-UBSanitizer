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
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int EIO ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  pci_set_consistent_dma_mask (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_dma_mask (struct pci_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int qlcnic_set_dma_mask(struct pci_dev *pdev, int *pci_using_dac)
{
	if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) &&
			!pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)))
		*pci_using_dac = 1;
	else if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) &&
			!pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32)))
		*pci_using_dac = 0;
	else {
		dev_err(&pdev->dev, "Unable to set DMA mask, aborting\n");
		return -EIO;
	}

	return 0;
}