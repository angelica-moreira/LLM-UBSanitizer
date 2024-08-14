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
typedef  int /*<<< orphan*/  u32 ;
struct radeon_device {int cg_flags; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MC_CG_ENABLE ; 
 int RADEON_CG_SUPPORT_MC_MGCG ; 
 int /*<<< orphan*/  RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * mc_cg_registers ; 

__attribute__((used)) static void cik_enable_mc_mgcg(struct radeon_device *rdev,
			       bool enable)
{
	int i;
	u32 orig, data;

	for (i = 0; i < ARRAY_SIZE(mc_cg_registers); i++) {
		orig = data = RREG32(mc_cg_registers[i]);
		if (enable && (rdev->cg_flags & RADEON_CG_SUPPORT_MC_MGCG))
			data |= MC_CG_ENABLE;
		else
			data &= ~MC_CG_ENABLE;
		if (data != orig)
			WREG32(mc_cg_registers[i], data);
	}
}