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
 int CACHE_LINE_SIZE ; 
 unsigned long calc_range_end (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  dsb () ; 
 int /*<<< orphan*/  l2_clean_pa_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  l2_inv_pa_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  l2_wt_override ; 

__attribute__((used)) static void feroceon_l2_flush_range(unsigned long start, unsigned long end)
{
	start &= ~(CACHE_LINE_SIZE - 1);
	end = (end + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1);
	while (start != end) {
		unsigned long range_end = calc_range_end(start, end);
		if (!l2_wt_override)
			l2_clean_pa_range(start, range_end - CACHE_LINE_SIZE);
		l2_inv_pa_range(start, range_end - CACHE_LINE_SIZE);
		start = range_end;
	}

	dsb();
}