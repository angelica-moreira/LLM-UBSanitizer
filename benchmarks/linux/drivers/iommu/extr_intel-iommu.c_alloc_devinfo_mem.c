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
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  iommu_devinfo_cache ; 
 void* kmem_cache_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void * alloc_devinfo_mem(void)
{
	return kmem_cache_alloc(iommu_devinfo_cache, GFP_ATOMIC);
}