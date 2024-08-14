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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MC_SEQ_RESERVE_M ; 
 int NOOFROWS_MASK ; 
 int NOOFROWS_SHIFT ; 
 int /*<<< orphan*/  RAMCFG ; 
 int RREG32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 calculate_memory_refresh_rate(struct radeon_device *rdev,
					 u32 engine_clock)
{
	u32 dram_rows, dram_refresh_rate;
	u32 tmp;

	tmp = (RREG32(RAMCFG) & NOOFROWS_MASK) >> NOOFROWS_SHIFT;
	dram_rows = 1 << (tmp + 10);
	dram_refresh_rate = 1 << ((RREG32(MC_SEQ_RESERVE_M) & 0x3) + 3);

	return ((engine_clock * 10) * dram_refresh_rate / dram_rows - 32) / 64;
}