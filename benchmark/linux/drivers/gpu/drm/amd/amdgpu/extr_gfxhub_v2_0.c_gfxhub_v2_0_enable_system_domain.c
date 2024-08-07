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
typedef  int /*<<< orphan*/  uint32_t ;
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENABLE_CONTEXT ; 
 int /*<<< orphan*/  GC ; 
 int /*<<< orphan*/  GCVM_CONTEXT0_CNTL ; 
 int /*<<< orphan*/  PAGE_TABLE_DEPTH ; 
 int /*<<< orphan*/  REG_SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmGCVM_CONTEXT0_CNTL ; 

__attribute__((used)) static void gfxhub_v2_0_enable_system_domain(struct amdgpu_device *adev)
{
	uint32_t tmp;

	tmp = RREG32_SOC15(GC, 0, mmGCVM_CONTEXT0_CNTL);
	tmp = REG_SET_FIELD(tmp, GCVM_CONTEXT0_CNTL, ENABLE_CONTEXT, 1);
	tmp = REG_SET_FIELD(tmp, GCVM_CONTEXT0_CNTL, PAGE_TABLE_DEPTH, 0);
	WREG32_SOC15(GC, 0, mmGCVM_CONTEXT0_CNTL, tmp);
}