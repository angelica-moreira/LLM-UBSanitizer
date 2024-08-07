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

/* Variables and functions */
 int MIC_DMA_DESC_RX_SIZE ; 

__attribute__((used)) static inline u32 mic_dma_hw_ring_dec(u32 val)
{
	return val ? val - 1 : MIC_DMA_DESC_RX_SIZE - 1;
}