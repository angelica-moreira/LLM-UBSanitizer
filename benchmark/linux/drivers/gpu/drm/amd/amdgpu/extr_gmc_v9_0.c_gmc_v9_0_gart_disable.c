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
struct amdgpu_device {scalar_t__ asic_type; } ;

/* Variables and functions */
 scalar_t__ CHIP_ARCTURUS ; 
 int /*<<< orphan*/  amdgpu_gart_table_vram_unpin (struct amdgpu_device*) ; 
 int /*<<< orphan*/  gfxhub_v1_0_gart_disable (struct amdgpu_device*) ; 
 int /*<<< orphan*/  mmhub_v1_0_gart_disable (struct amdgpu_device*) ; 
 int /*<<< orphan*/  mmhub_v9_4_gart_disable (struct amdgpu_device*) ; 

__attribute__((used)) static void gmc_v9_0_gart_disable(struct amdgpu_device *adev)
{
	gfxhub_v1_0_gart_disable(adev);
	if (adev->asic_type == CHIP_ARCTURUS)
		mmhub_v9_4_gart_disable(adev);
	else
		mmhub_v1_0_gart_disable(adev);
	amdgpu_gart_table_vram_unpin(adev);
}