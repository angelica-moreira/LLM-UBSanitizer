#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  sq_irq; int /*<<< orphan*/  cp_ecc_error_irq; int /*<<< orphan*/  priv_inst_irq; int /*<<< orphan*/  priv_reg_irq; } ;
struct amdgpu_device {TYPE_1__ gfx; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*,int) ; 
 int amdgpu_irq_get (struct amdgpu_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int gfx_v8_0_do_edc_gpr_workarounds (struct amdgpu_device*) ; 

__attribute__((used)) static int gfx_v8_0_late_init(void *handle)
{
	struct amdgpu_device *adev = (struct amdgpu_device *)handle;
	int r;

	r = amdgpu_irq_get(adev, &adev->gfx.priv_reg_irq, 0);
	if (r)
		return r;

	r = amdgpu_irq_get(adev, &adev->gfx.priv_inst_irq, 0);
	if (r)
		return r;

	/* requires IBs so do in late init after IB pool is initialized */
	r = gfx_v8_0_do_edc_gpr_workarounds(adev);
	if (r)
		return r;

	r = amdgpu_irq_get(adev, &adev->gfx.cp_ecc_error_irq, 0);
	if (r) {
		DRM_ERROR("amdgpu_irq_get() failed to get IRQ for EDC, r: %d.\n", r);
		return r;
	}

	r = amdgpu_irq_get(adev, &adev->gfx.sq_irq, 0);
	if (r) {
		DRM_ERROR(
			"amdgpu_irq_get() failed to get IRQ for SQ, r: %d.\n",
			r);
		return r;
	}

	return 0;
}