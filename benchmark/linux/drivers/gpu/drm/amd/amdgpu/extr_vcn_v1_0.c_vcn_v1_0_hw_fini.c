#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int ready; } ;
struct amdgpu_ring {TYPE_3__ sched; } ;
struct TYPE_5__ {TYPE_1__* inst; } ;
struct amdgpu_device {int pg_flags; TYPE_2__ vcn; } ;
struct TYPE_4__ {struct amdgpu_ring ring_dec; } ;

/* Variables and functions */
 int /*<<< orphan*/  AMD_PG_STATE_GATE ; 
 int AMD_PG_SUPPORT_VCN_DPG ; 
 scalar_t__ RREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VCN ; 
 int /*<<< orphan*/  mmUVD_STATUS ; 
 int /*<<< orphan*/  vcn_v1_0_set_powergating_state (struct amdgpu_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int vcn_v1_0_hw_fini(void *handle)
{
	struct amdgpu_device *adev = (struct amdgpu_device *)handle;
	struct amdgpu_ring *ring = &adev->vcn.inst->ring_dec;

	if ((adev->pg_flags & AMD_PG_SUPPORT_VCN_DPG) ||
		RREG32_SOC15(VCN, 0, mmUVD_STATUS))
		vcn_v1_0_set_powergating_state(adev, AMD_PG_STATE_GATE);

	ring->sched.ready = false;

	return 0;
}