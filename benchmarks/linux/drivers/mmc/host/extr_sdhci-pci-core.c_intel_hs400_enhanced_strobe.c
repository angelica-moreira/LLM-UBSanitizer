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
typedef  int /*<<< orphan*/  u32 ;
struct sdhci_host {int dummy; } ;
struct mmc_ios {scalar_t__ enhanced_strobe; } ;
struct mmc_host {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTEL_HS400_ES_BIT ; 
 int /*<<< orphan*/  INTEL_HS400_ES_REG ; 
 struct sdhci_host* mmc_priv (struct mmc_host*) ; 
 int /*<<< orphan*/  sdhci_readl (struct sdhci_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdhci_writel (struct sdhci_host*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void intel_hs400_enhanced_strobe(struct mmc_host *mmc,
					struct mmc_ios *ios)
{
	struct sdhci_host *host = mmc_priv(mmc);
	u32 val;

	val = sdhci_readl(host, INTEL_HS400_ES_REG);
	if (ios->enhanced_strobe)
		val |= INTEL_HS400_ES_BIT;
	else
		val &= ~INTEL_HS400_ES_BIT;
	sdhci_writel(host, val, INTEL_HS400_ES_REG);
}