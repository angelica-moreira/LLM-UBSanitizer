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
struct mmc_host {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mmc_priv (struct mmc_host*) ; 
 int /*<<< orphan*/  sdhci_dumpregs (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sdhci_pci_dumpregs(struct mmc_host *mmc)
{
	sdhci_dumpregs(mmc_priv(mmc));
}