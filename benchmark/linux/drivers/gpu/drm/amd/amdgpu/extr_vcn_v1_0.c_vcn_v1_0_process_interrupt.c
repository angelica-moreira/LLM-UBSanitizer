#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct amdgpu_iv_entry {int src_id; int /*<<< orphan*/ * src_data; } ;
struct amdgpu_irq_src {int dummy; } ;
struct TYPE_4__ {TYPE_1__* inst; } ;
struct amdgpu_device {TYPE_2__ vcn; } ;
struct TYPE_3__ {int /*<<< orphan*/  ring_jpeg; int /*<<< orphan*/ * ring_enc; int /*<<< orphan*/  ring_dec; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*) ; 
 int /*<<< orphan*/  DRM_ERROR (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amdgpu_fence_process (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vcn_v1_0_process_interrupt(struct amdgpu_device *adev,
				      struct amdgpu_irq_src *source,
				      struct amdgpu_iv_entry *entry)
{
	DRM_DEBUG("IH: VCN TRAP\n");

	switch (entry->src_id) {
	case 124:
		amdgpu_fence_process(&adev->vcn.inst->ring_dec);
		break;
	case 119:
		amdgpu_fence_process(&adev->vcn.inst->ring_enc[0]);
		break;
	case 120:
		amdgpu_fence_process(&adev->vcn.inst->ring_enc[1]);
		break;
	case 126:
		amdgpu_fence_process(&adev->vcn.inst->ring_jpeg);
		break;
	default:
		DRM_ERROR("Unhandled interrupt: %d %d\n",
			  entry->src_id, entry->src_data[0]);
		break;
	}

	return 0;
}