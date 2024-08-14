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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CG_VDDC3D_OOR ; 
 int /*<<< orphan*/  SU (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SU_MASK ; 
 int /*<<< orphan*/  WREG32_P (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void r600_set_vddc3d_oorsu(struct radeon_device *rdev, u32 u)
{
	WREG32_P(CG_VDDC3D_OOR, SU(u), ~SU_MASK);
}