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
typedef  int u32 ;
struct at_dma {int dummy; } ;

/* Variables and functions */
 int AT_DMA_BTC (int) ; 
 int AT_DMA_ERR (int) ; 
 int /*<<< orphan*/  EBCIDR ; 
 int /*<<< orphan*/  EBCIER ; 
 int /*<<< orphan*/  dma_writel (struct at_dma*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void atc_setup_irq(struct at_dma *atdma, int chan_id, int on)
{
	u32 ebci;

	/* enable interrupts on buffer transfer completion & error */
	ebci =    AT_DMA_BTC(chan_id)
		| AT_DMA_ERR(chan_id);
	if (on)
		dma_writel(atdma, EBCIER, ebci);
	else
		dma_writel(atdma, EBCIDR, ebci);
}