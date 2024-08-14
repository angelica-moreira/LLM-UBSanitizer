#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned long line_size; } ;

/* Variables and functions */
 size_t DCACHE ; 
 TYPE_1__* L1_cache_info ; 

void cpu_dcache_inval_range(unsigned long start, unsigned long end)
{
	unsigned long line_size;

	line_size = L1_cache_info[DCACHE].line_size;

	while (end > start) {
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (start));
		start += line_size;
	}
}