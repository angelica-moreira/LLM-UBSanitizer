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
struct moxart_chan {scalar_t__ base; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 scalar_t__ REG_OFF_ADDRESS_DEST ; 
 scalar_t__ REG_OFF_ADDRESS_SOURCE ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void moxart_dma_set_params(struct moxart_chan *ch, dma_addr_t src_addr,
				  dma_addr_t dst_addr)
{
	writel(src_addr, ch->base + REG_OFF_ADDRESS_SOURCE);
	writel(dst_addr, ch->base + REG_OFF_ADDRESS_DEST);
}