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
typedef  int u64 ;
typedef  scalar_t__ u32 ;

/* Variables and functions */
 int SPT_PMC_SLP_S0_RES_COUNTER_STEP ; 

__attribute__((used)) static inline u64 pmc_core_adjust_slp_s0_step(u32 value)
{
	return (u64)value * SPT_PMC_SLP_S0_RES_COUNTER_STEP;
}