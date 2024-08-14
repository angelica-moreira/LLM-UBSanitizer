#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct stmmac_tx_queue {unsigned int dirty_tx; TYPE_1__* tx_skbuff_dma; struct stmmac_priv* priv_data; } ;
struct stmmac_priv {scalar_t__ hwts_tx_en; int /*<<< orphan*/  extend_desc; } ;
struct dma_desc {scalar_t__ des3; } ;
struct TYPE_2__ {scalar_t__ last_segment; scalar_t__ is_jumbo; } ;

/* Variables and functions */
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void clean_desc3(void *priv_ptr, struct dma_desc *p)
{
	struct stmmac_tx_queue *tx_q = (struct stmmac_tx_queue *)priv_ptr;
	struct stmmac_priv *priv = tx_q->priv_data;
	unsigned int entry = tx_q->dirty_tx;

	/* des3 is only used for jumbo frames tx or time stamping */
	if (unlikely(tx_q->tx_skbuff_dma[entry].is_jumbo ||
		     (tx_q->tx_skbuff_dma[entry].last_segment &&
		      !priv->extend_desc && priv->hwts_tx_en)))
		p->des3 = 0;
}