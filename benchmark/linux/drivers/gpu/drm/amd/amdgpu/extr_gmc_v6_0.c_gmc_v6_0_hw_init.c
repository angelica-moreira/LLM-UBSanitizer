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
struct amdgpu_device {int flags; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int AMD_IS_APU ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int gmc_v6_0_gart_enable (struct amdgpu_device*) ; 
 int gmc_v6_0_mc_load_microcode (struct amdgpu_device*) ; 
 int /*<<< orphan*/  gmc_v6_0_mc_program (struct amdgpu_device*) ; 

__attribute__((used)) static int gmc_v6_0_hw_init(void *handle)
{
	int r;
	struct amdgpu_device *adev = (struct amdgpu_device *)handle;

	gmc_v6_0_mc_program(adev);

	if (!(adev->flags & AMD_IS_APU)) {
		r = gmc_v6_0_mc_load_microcode(adev);
		if (r) {
			dev_err(adev->dev, "Failed to load MC firmware!\n");
			return r;
		}
	}

	r = gmc_v6_0_gart_enable(adev);
	if (r)
		return r;

	return r;
}