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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VCE_CGTT_CLK_OVERRIDE ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void vce_v2_0_disable_cg(struct radeon_device *rdev)
{
	WREG32(VCE_CGTT_CLK_OVERRIDE, 7);
}