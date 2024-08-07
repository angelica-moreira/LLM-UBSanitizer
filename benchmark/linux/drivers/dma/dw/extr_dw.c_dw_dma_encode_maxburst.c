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
struct dw_dma_chan {int dummy; } ;

/* Variables and functions */
 int fls (int) ; 

__attribute__((used)) static void dw_dma_encode_maxburst(struct dw_dma_chan *dwc, u32 *maxburst)
{
	/*
	 * Fix burst size according to dw_dmac. We need to convert them as:
	 * 1 -> 0, 4 -> 1, 8 -> 2, 16 -> 3.
	 */
	*maxburst = *maxburst > 1 ? fls(*maxburst) - 2 : 0;
}