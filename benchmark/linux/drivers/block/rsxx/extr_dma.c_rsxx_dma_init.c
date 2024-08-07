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

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  KMEM_CACHE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SLAB_HWCACHE_ALIGN ; 
 int /*<<< orphan*/  rsxx_dma ; 
 int /*<<< orphan*/  rsxx_dma_pool ; 

int rsxx_dma_init(void)
{
	rsxx_dma_pool = KMEM_CACHE(rsxx_dma, SLAB_HWCACHE_ALIGN);
	if (!rsxx_dma_pool)
		return -ENOMEM;

	return 0;
}