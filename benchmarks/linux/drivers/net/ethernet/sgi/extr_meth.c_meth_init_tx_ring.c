#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct meth_private {int /*<<< orphan*/  tx_skb_dmas; int /*<<< orphan*/  tx_skbs; int /*<<< orphan*/  tx_ring_dma; scalar_t__ tx_write; scalar_t__ tx_read; scalar_t__ tx_count; int /*<<< orphan*/  tx_ring; TYPE_2__* pdev; } ;
struct TYPE_4__ {int /*<<< orphan*/  tx_ring_base; } ;
struct TYPE_6__ {TYPE_1__ eth; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  TX_RING_BUFFER_SIZE ; 
 int /*<<< orphan*/  dma_alloc_coherent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_3__* mace ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int meth_init_tx_ring(struct meth_private *priv)
{
	/* Init TX ring */
	priv->tx_ring = dma_alloc_coherent(&priv->pdev->dev,
			TX_RING_BUFFER_SIZE, &priv->tx_ring_dma, GFP_ATOMIC);
	if (!priv->tx_ring)
		return -ENOMEM;

	priv->tx_count = priv->tx_read = priv->tx_write = 0;
	mace->eth.tx_ring_base = priv->tx_ring_dma;
	/* Now init skb save area */
	memset(priv->tx_skbs, 0, sizeof(priv->tx_skbs));
	memset(priv->tx_skb_dmas, 0, sizeof(priv->tx_skb_dmas));
	return 0;
}