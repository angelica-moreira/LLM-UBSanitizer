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
 int DTLB_ARF_WAYS ; 
 int PAGE_SHIFT ; 
 int XCHAL_DTLB_ARF_ENTRIES_LOG2 ; 
 int /*<<< orphan*/  invalidate_dtlb_entry_no_isync (int) ; 

__attribute__((used)) static inline void __flush_dtlb_all (void)
{
	int w, i;

	for (w = 0; w < DTLB_ARF_WAYS; w++) {
		for (i = 0; i < (1 << XCHAL_DTLB_ARF_ENTRIES_LOG2); i++) {
			int e = w + (i << PAGE_SHIFT);
			invalidate_dtlb_entry_no_isync(e);
		}
	}
	asm volatile ("isync\n");
}