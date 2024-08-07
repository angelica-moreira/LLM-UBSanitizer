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
typedef  int u32 ;

/* Variables and functions */
 int idx_to_reg_bit (int) ; 

__attribute__((used)) static inline bool cluster_pmu_counter_has_overflowed(u32 ovsr, u32 idx)
{
	return !!(ovsr & idx_to_reg_bit(idx));
}