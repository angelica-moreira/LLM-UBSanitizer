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
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GC ; 
 int /*<<< orphan*/  RLC_CNTL ; 
 int /*<<< orphan*/  RLC_ENABLE_F32 ; 
 int /*<<< orphan*/  WREG32_FIELD15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gfx_v9_0_enable_gui_idle_interrupt (struct amdgpu_device*,int) ; 
 int /*<<< orphan*/  gfx_v9_0_wait_for_rlc_serdes (struct amdgpu_device*) ; 

void gfx_v9_0_rlc_stop(struct amdgpu_device *adev)
{
	WREG32_FIELD15(GC, 0, RLC_CNTL, RLC_ENABLE_F32, 0);
	gfx_v9_0_enable_gui_idle_interrupt(adev, false);
	gfx_v9_0_wait_for_rlc_serdes(adev);
}