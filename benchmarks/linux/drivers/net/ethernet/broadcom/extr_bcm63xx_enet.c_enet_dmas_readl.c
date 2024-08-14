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
typedef  scalar_t__ u32 ;
struct bcm_enet_priv {int dma_chan_width; } ;

/* Variables and functions */
 scalar_t__* bcm_enet_shared_base ; 
 scalar_t__ bcm_readl (scalar_t__) ; 

__attribute__((used)) static inline u32 enet_dmas_readl(struct bcm_enet_priv *priv, u32 off, int chan)
{
	return bcm_readl(bcm_enet_shared_base[2] + off + chan * priv->dma_chan_width);
}