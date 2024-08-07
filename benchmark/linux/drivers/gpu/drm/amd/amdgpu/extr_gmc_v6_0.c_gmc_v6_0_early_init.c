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
 int /*<<< orphan*/  gmc_v6_0_set_gmc_funcs (struct amdgpu_device*) ; 
 int /*<<< orphan*/  gmc_v6_0_set_irq_funcs (struct amdgpu_device*) ; 

__attribute__((used)) static int gmc_v6_0_early_init(void *handle)
{
	struct amdgpu_device *adev = (struct amdgpu_device *)handle;

	gmc_v6_0_set_gmc_funcs(adev);
	gmc_v6_0_set_irq_funcs(adev);

	return 0;
}