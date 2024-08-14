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
 size_t ICACHE ; 
 TYPE_1__* L1_cache_info ; 
 unsigned long PAGE_SIZE ; 
 int /*<<< orphan*/  __nds32__isb () ; 

void cpu_icache_inval_page(unsigned long start)
{
	unsigned long line_size, end;

	line_size = L1_cache_info[ICACHE].line_size;
	end = start + PAGE_SIZE;

	do {
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
	} while (end != start);
	__nds32__isb();
}