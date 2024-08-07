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
struct fsldma_chan {int dummy; } ;

/* Variables and functions */
 int FSL_DMA_SR_CB ; 
 int FSL_DMA_SR_CH ; 
 int get_sr (struct fsldma_chan*) ; 

__attribute__((used)) static int dma_is_idle(struct fsldma_chan *chan)
{
	u32 sr = get_sr(chan);
	return (!(sr & FSL_DMA_SR_CB)) || (sr & FSL_DMA_SR_CH);
}