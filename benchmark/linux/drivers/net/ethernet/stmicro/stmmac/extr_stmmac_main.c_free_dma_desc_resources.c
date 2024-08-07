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
struct stmmac_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  free_dma_rx_desc_resources (struct stmmac_priv*) ; 
 int /*<<< orphan*/  free_dma_tx_desc_resources (struct stmmac_priv*) ; 

__attribute__((used)) static void free_dma_desc_resources(struct stmmac_priv *priv)
{
	/* Release the DMA RX socket buffers */
	free_dma_rx_desc_resources(priv);

	/* Release the DMA TX socket buffers */
	free_dma_tx_desc_resources(priv);
}