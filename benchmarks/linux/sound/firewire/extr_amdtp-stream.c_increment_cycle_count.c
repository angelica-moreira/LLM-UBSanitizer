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
typedef  unsigned int u32 ;

/* Variables and functions */
 int CYCLES_PER_SECOND ; 

__attribute__((used)) static inline u32 increment_cycle_count(u32 cycle, unsigned int addend)
{
	cycle += addend;
	if (cycle >= 8 * CYCLES_PER_SECOND)
		cycle -= 8 * CYCLES_PER_SECOND;
	return cycle;
}