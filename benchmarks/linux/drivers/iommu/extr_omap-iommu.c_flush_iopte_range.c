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
typedef  int /*<<< orphan*/  u32 ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_TO_DEVICE ; 
 int /*<<< orphan*/  dma_sync_single_range_for_device (struct device*,int /*<<< orphan*/ ,unsigned long,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void flush_iopte_range(struct device *dev, dma_addr_t dma,
			      unsigned long offset, int num_entries)
{
	size_t size = num_entries * sizeof(u32);

	dma_sync_single_range_for_device(dev, dma, offset, size, DMA_TO_DEVICE);
}