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
struct radeon_device {scalar_t__ has_uvd; } ;

/* Variables and functions */
 int RADEON_CG_BLOCK_BIF ; 
 int RADEON_CG_BLOCK_GFX ; 
 int RADEON_CG_BLOCK_HDP ; 
 int RADEON_CG_BLOCK_MC ; 
 int RADEON_CG_BLOCK_SDMA ; 
 int RADEON_CG_BLOCK_UVD ; 
 int /*<<< orphan*/  cik_update_cg (struct radeon_device*,int,int) ; 
 int /*<<< orphan*/  si_init_uvd_internal_cg (struct radeon_device*) ; 

__attribute__((used)) static void cik_init_cg(struct radeon_device *rdev)
{

	cik_update_cg(rdev, RADEON_CG_BLOCK_GFX, true);

	if (rdev->has_uvd)
		si_init_uvd_internal_cg(rdev);

	cik_update_cg(rdev, (RADEON_CG_BLOCK_MC |
			     RADEON_CG_BLOCK_SDMA |
			     RADEON_CG_BLOCK_BIF |
			     RADEON_CG_BLOCK_UVD |
			     RADEON_CG_BLOCK_HDP), true);
}