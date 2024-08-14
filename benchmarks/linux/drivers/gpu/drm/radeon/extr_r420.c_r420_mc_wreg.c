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
typedef  int u32 ;
struct radeon_device {int /*<<< orphan*/  mc_idx_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  R_0001F8_MC_IND_INDEX ; 
 int /*<<< orphan*/  R_0001FC_MC_IND_DATA ; 
 int S_0001F8_MC_IND_ADDR (int) ; 
 int S_0001F8_MC_IND_WR_EN (int) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

void r420_mc_wreg(struct radeon_device *rdev, u32 reg, u32 v)
{
	unsigned long flags;

	spin_lock_irqsave(&rdev->mc_idx_lock, flags);
	WREG32(R_0001F8_MC_IND_INDEX, S_0001F8_MC_IND_ADDR(reg) |
		S_0001F8_MC_IND_WR_EN(1));
	WREG32(R_0001FC_MC_IND_DATA, v);
	spin_unlock_irqrestore(&rdev->mc_idx_lock, flags);
}