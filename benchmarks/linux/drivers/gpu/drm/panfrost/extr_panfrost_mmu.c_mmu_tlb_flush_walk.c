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
 int /*<<< orphan*/  mmu_tlb_sync_context (void*) ; 

__attribute__((used)) static void mmu_tlb_flush_walk(unsigned long iova, size_t size, size_t granule,
			       void *cookie)
{
	mmu_tlb_sync_context(cookie);
}