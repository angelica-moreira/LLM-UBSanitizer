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
struct radeon_ring {int /*<<< orphan*/  wptr; } ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  UVD_RBC_RB_WPTR ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void uvd_v1_0_set_wptr(struct radeon_device *rdev,
		       struct radeon_ring *ring)
{
	WREG32(UVD_RBC_RB_WPTR, ring->wptr);
}