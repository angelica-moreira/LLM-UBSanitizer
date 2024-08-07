#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct stmmac_priv {int /*<<< orphan*/  hw; TYPE_2__* plat; } ;
struct TYPE_4__ {size_t tx_queues_to_use; TYPE_1__* tx_queues_cfg; } ;
struct TYPE_3__ {size_t weight; } ;

/* Variables and functions */
 int /*<<< orphan*/  stmmac_set_mtl_tx_queue_weight (struct stmmac_priv*,int /*<<< orphan*/ ,size_t,size_t) ; 

__attribute__((used)) static void stmmac_set_tx_queue_weight(struct stmmac_priv *priv)
{
	u32 tx_queues_count = priv->plat->tx_queues_to_use;
	u32 weight;
	u32 queue;

	for (queue = 0; queue < tx_queues_count; queue++) {
		weight = priv->plat->tx_queues_cfg[queue].weight;
		stmmac_set_mtl_tx_queue_weight(priv, priv->hw, weight, queue);
	}
}