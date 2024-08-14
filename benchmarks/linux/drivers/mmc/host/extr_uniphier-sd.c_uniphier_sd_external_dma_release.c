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
struct uniphier_sd_priv {scalar_t__ chan; } ;
struct tmio_mmc_host {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_release_channel (scalar_t__) ; 
 struct uniphier_sd_priv* uniphier_sd_priv (struct tmio_mmc_host*) ; 

__attribute__((used)) static void uniphier_sd_external_dma_release(struct tmio_mmc_host *host)
{
	struct uniphier_sd_priv *priv = uniphier_sd_priv(host);

	if (priv->chan)
		dma_release_channel(priv->chan);
}