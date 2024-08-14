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
struct radeon_device {scalar_t__ has_vce; scalar_t__ has_uvd; } ;

/* Variables and functions */
 int /*<<< orphan*/  cayman_dma_stop (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_audio_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_pm_suspend (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_uvd_suspend (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_vce_suspend (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_vm_manager_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_wb_disable (struct radeon_device*) ; 
 int /*<<< orphan*/  si_cp_enable (struct radeon_device*,int) ; 
 int /*<<< orphan*/  si_fini_cg (struct radeon_device*) ; 
 int /*<<< orphan*/  si_fini_pg (struct radeon_device*) ; 
 int /*<<< orphan*/  si_irq_suspend (struct radeon_device*) ; 
 int /*<<< orphan*/  si_pcie_gart_disable (struct radeon_device*) ; 
 int /*<<< orphan*/  uvd_v1_0_fini (struct radeon_device*) ; 

int si_suspend(struct radeon_device *rdev)
{
	radeon_pm_suspend(rdev);
	radeon_audio_fini(rdev);
	radeon_vm_manager_fini(rdev);
	si_cp_enable(rdev, false);
	cayman_dma_stop(rdev);
	if (rdev->has_uvd) {
		uvd_v1_0_fini(rdev);
		radeon_uvd_suspend(rdev);
	}
	if (rdev->has_vce)
		radeon_vce_suspend(rdev);
	si_fini_pg(rdev);
	si_fini_cg(rdev);
	si_irq_suspend(rdev);
	radeon_wb_disable(rdev);
	si_pcie_gart_disable(rdev);
	return 0;
}