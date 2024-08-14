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
 int gmc_v10_0_gart_enable (struct amdgpu_device*) ; 
 int /*<<< orphan*/  gmc_v10_0_init_golden_registers (struct amdgpu_device*) ; 

__attribute__((used)) static int gmc_v10_0_hw_init(void *handle)
{
	int r;
	struct amdgpu_device *adev = (struct amdgpu_device *)handle;

	/* The sequence of these two function calls matters.*/
	gmc_v10_0_init_golden_registers(adev);

	r = gmc_v10_0_gart_enable(adev);
	if (r)
		return r;

	return 0;
}