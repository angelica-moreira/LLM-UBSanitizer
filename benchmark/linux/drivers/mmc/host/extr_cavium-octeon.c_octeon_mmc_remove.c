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
typedef  int /*<<< orphan*/  u64 ;
struct platform_device {int dummy; } ;
struct cvm_mmc_host {scalar_t__ dma_base; scalar_t__* slot; } ;

/* Variables and functions */
 int CAVIUM_MAX_MMC ; 
 scalar_t__ MIO_EMM_DMA_CFG (struct cvm_mmc_host*) ; 
 int /*<<< orphan*/  MIO_EMM_DMA_CFG_EN ; 
 int /*<<< orphan*/  cvm_mmc_of_slot_remove (scalar_t__) ; 
 int /*<<< orphan*/  octeon_mmc_set_shared_power (struct cvm_mmc_host*,int /*<<< orphan*/ ) ; 
 struct cvm_mmc_host* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  readq (scalar_t__) ; 
 int /*<<< orphan*/  writeq (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int octeon_mmc_remove(struct platform_device *pdev)
{
	struct cvm_mmc_host *host = platform_get_drvdata(pdev);
	u64 dma_cfg;
	int i;

	for (i = 0; i < CAVIUM_MAX_MMC; i++)
		if (host->slot[i])
			cvm_mmc_of_slot_remove(host->slot[i]);

	dma_cfg = readq(host->dma_base + MIO_EMM_DMA_CFG(host));
	dma_cfg &= ~MIO_EMM_DMA_CFG_EN;
	writeq(dma_cfg, host->dma_base + MIO_EMM_DMA_CFG(host));

	octeon_mmc_set_shared_power(host, 0);
	return 0;
}