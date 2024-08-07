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
struct device {int dummy; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYNC_FOR_CPU ; 
 int /*<<< orphan*/  bounce_sync_single (struct device*,int /*<<< orphan*/ ,size_t,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bounce_sync_single_for_cpu(struct device *dev, dma_addr_t addr,
			   size_t size, enum dma_data_direction dir)
{
	bounce_sync_single(dev, addr, size, dir, SYNC_FOR_CPU);
}