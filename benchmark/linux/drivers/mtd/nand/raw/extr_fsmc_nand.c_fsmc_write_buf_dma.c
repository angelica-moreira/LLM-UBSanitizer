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
typedef  int /*<<< orphan*/  u8 ;
struct fsmc_nand_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_TO_DEVICE ; 
 int /*<<< orphan*/  dma_xfer (struct fsmc_nand_data*,void*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fsmc_write_buf_dma(struct fsmc_nand_data *host, const u8 *buf,
			       int len)
{
	dma_xfer(host, (void *)buf, len, DMA_TO_DEVICE);
}