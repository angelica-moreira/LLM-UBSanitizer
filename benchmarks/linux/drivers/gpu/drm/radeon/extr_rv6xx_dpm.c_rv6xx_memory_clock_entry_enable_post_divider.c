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
 int /*<<< orphan*/  LEVEL0_MPLL_DIV_EN ; 
 scalar_t__ MPLL_FREQ_LEVEL_0 ; 
 int /*<<< orphan*/  WREG32_P (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rv6xx_memory_clock_entry_enable_post_divider(struct radeon_device *rdev,
							 u32 index, bool enable)
{
	if (enable)
		WREG32_P(MPLL_FREQ_LEVEL_0 + (index * 4),
			 LEVEL0_MPLL_DIV_EN, ~LEVEL0_MPLL_DIV_EN);
	else
		WREG32_P(MPLL_FREQ_LEVEL_0 + (index * 4), 0, ~LEVEL0_MPLL_DIV_EN);
}