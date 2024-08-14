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
struct bgmac {int /*<<< orphan*/ * rx_ring; int /*<<< orphan*/ * tx_ring; } ;

/* Variables and functions */
 int BGMAC_MAX_RX_RINGS ; 
 int BGMAC_MAX_TX_RINGS ; 
 int /*<<< orphan*/  BGMAC_RX_RING_SLOTS ; 
 int /*<<< orphan*/  BGMAC_TX_RING_SLOTS ; 
 int /*<<< orphan*/  bgmac_dma_ring_desc_free (struct bgmac*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bgmac_dma_free(struct bgmac *bgmac)
{
	int i;

	for (i = 0; i < BGMAC_MAX_TX_RINGS; i++)
		bgmac_dma_ring_desc_free(bgmac, &bgmac->tx_ring[i],
					 BGMAC_TX_RING_SLOTS);

	for (i = 0; i < BGMAC_MAX_RX_RINGS; i++)
		bgmac_dma_ring_desc_free(bgmac, &bgmac->rx_ring[i],
					 BGMAC_RX_RING_SLOTS);
}