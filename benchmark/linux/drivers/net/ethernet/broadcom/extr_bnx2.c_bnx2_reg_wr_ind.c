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
typedef  int /*<<< orphan*/  u32 ;
struct bnx2 {int /*<<< orphan*/  indirect_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNX2_PCICFG_REG_WINDOW ; 
 int /*<<< orphan*/  BNX2_PCICFG_REG_WINDOW_ADDRESS ; 
 int /*<<< orphan*/  BNX2_WR (struct bnx2*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void
bnx2_reg_wr_ind(struct bnx2 *bp, u32 offset, u32 val)
{
	unsigned long flags;

	spin_lock_irqsave(&bp->indirect_lock, flags);
	BNX2_WR(bp, BNX2_PCICFG_REG_WINDOW_ADDRESS, offset);
	BNX2_WR(bp, BNX2_PCICFG_REG_WINDOW, val);
	spin_unlock_irqrestore(&bp->indirect_lock, flags);
}