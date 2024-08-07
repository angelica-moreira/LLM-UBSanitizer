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
 int BSP (int /*<<< orphan*/ ) ; 
 int BSU (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CG_BSP ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int) ; 

void r600_set_bsp(struct radeon_device *rdev, u32 u, u32 p)
{
	WREG32(CG_BSP, BSP(p) | BSU(u));
}