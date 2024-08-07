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
struct radeon_device {int /*<<< orphan*/  pcie_idx_lock; int /*<<< orphan*/  pcie_reg_mask; } ;
typedef  int /*<<< orphan*/  reg ;

/* Variables and functions */
 int /*<<< orphan*/  RADEON_PCIE_DATA ; 
 int /*<<< orphan*/  RADEON_PCIE_INDEX ; 
 int /*<<< orphan*/  RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

uint32_t rv370_pcie_rreg(struct radeon_device *rdev, uint32_t reg)
{
	unsigned long flags;
	uint32_t r;

	spin_lock_irqsave(&rdev->pcie_idx_lock, flags);
	WREG32(RADEON_PCIE_INDEX, ((reg) & rdev->pcie_reg_mask));
	r = RREG32(RADEON_PCIE_DATA);
	spin_unlock_irqrestore(&rdev->pcie_idx_lock, flags);
	return r;
}