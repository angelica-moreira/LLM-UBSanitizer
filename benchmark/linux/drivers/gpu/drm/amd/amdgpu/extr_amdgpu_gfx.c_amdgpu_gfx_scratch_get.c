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
typedef  scalar_t__ uint32_t ;
struct TYPE_4__ {unsigned int free_mask; int num_reg; scalar_t__ reg_base; } ;
struct TYPE_3__ {TYPE_2__ scratch; } ;
struct amdgpu_device {TYPE_1__ gfx; } ;

/* Variables and functions */
 int EINVAL ; 
 int ffs (unsigned int) ; 

int amdgpu_gfx_scratch_get(struct amdgpu_device *adev, uint32_t *reg)
{
	int i;

	i = ffs(adev->gfx.scratch.free_mask);
	if (i != 0 && i <= adev->gfx.scratch.num_reg) {
		i--;
		adev->gfx.scratch.free_mask &= ~(1u << i);
		*reg = adev->gfx.scratch.reg_base + i;
		return 0;
	}
	return -EINVAL;
}