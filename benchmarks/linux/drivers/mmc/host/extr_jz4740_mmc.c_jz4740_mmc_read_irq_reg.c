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
typedef  int /*<<< orphan*/  uint32_t ;
struct jz4740_mmc_host {scalar_t__ version; scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ JZ_MMC_JZ4780 ; 
 scalar_t__ JZ_REG_MMC_IREG ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  readw (scalar_t__) ; 

__attribute__((used)) static uint32_t jz4740_mmc_read_irq_reg(struct jz4740_mmc_host *host)
{
	if (host->version >= JZ_MMC_JZ4780)
		return readl(host->base + JZ_REG_MMC_IREG);
	else
		return readw(host->base + JZ_REG_MMC_IREG);
}