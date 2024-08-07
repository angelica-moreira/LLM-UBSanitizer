#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int dummy; } ;
struct page {int /*<<< orphan*/  flags; } ;
typedef  int /*<<< orphan*/  pte_t ;
struct TYPE_3__ {int /*<<< orphan*/  n_aliases; } ;
struct TYPE_4__ {TYPE_1__ dcache; } ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PG_dcache_clean ; 
 int /*<<< orphan*/  __flush_purge_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ boot_cpu_data ; 
 int /*<<< orphan*/  page_address (struct page*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 scalar_t__ pfn_valid (unsigned long) ; 
 unsigned long pte_pfn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void __update_cache(struct vm_area_struct *vma,
		    unsigned long address, pte_t pte)
{
	struct page *page;
	unsigned long pfn = pte_pfn(pte);

	if (!boot_cpu_data.dcache.n_aliases)
		return;

	page = pfn_to_page(pfn);
	if (pfn_valid(pfn)) {
		int dirty = !test_and_set_bit(PG_dcache_clean, &page->flags);
		if (dirty)
			__flush_purge_region(page_address(page), PAGE_SIZE);
	}
}