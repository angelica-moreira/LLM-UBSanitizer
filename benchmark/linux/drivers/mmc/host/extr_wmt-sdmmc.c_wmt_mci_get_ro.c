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
struct wmt_mci_priv {scalar_t__ sdmmc_base; } ;
struct mmc_host {int dummy; } ;

/* Variables and functions */
 scalar_t__ SDMMC_STS0 ; 
 int STS0_WRITE_PROTECT ; 
 struct wmt_mci_priv* mmc_priv (struct mmc_host*) ; 
 int readb (scalar_t__) ; 

__attribute__((used)) static int wmt_mci_get_ro(struct mmc_host *mmc)
{
	struct wmt_mci_priv *priv = mmc_priv(mmc);

	return !(readb(priv->sdmmc_base + SDMMC_STS0) & STS0_WRITE_PROTECT);
}