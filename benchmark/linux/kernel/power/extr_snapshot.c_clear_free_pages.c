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
struct memory_bitmap {int dummy; } ;

/* Variables and functions */
 unsigned long BM_END_OF_MAP ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  clear_highpage (int /*<<< orphan*/ ) ; 
 struct memory_bitmap* free_pages_map ; 
 unsigned long memory_bm_next_pfn (struct memory_bitmap*) ; 
 int /*<<< orphan*/  memory_bm_position_reset (struct memory_bitmap*) ; 
 int /*<<< orphan*/  pfn_to_page (unsigned long) ; 
 scalar_t__ pfn_valid (unsigned long) ; 
 int /*<<< orphan*/  pr_info (char*) ; 

void clear_free_pages(void)
{
#ifdef CONFIG_PAGE_POISONING_ZERO
	struct memory_bitmap *bm = free_pages_map;
	unsigned long pfn;

	if (WARN_ON(!(free_pages_map)))
		return;

	memory_bm_position_reset(bm);
	pfn = memory_bm_next_pfn(bm);
	while (pfn != BM_END_OF_MAP) {
		if (pfn_valid(pfn))
			clear_highpage(pfn_to_page(pfn));

		pfn = memory_bm_next_pfn(bm);
	}
	memory_bm_position_reset(bm);
	pr_info("free pages cleared after restore\n");
#endif /* PAGE_POISONING_ZERO */
}