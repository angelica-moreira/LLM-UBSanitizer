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
struct clk_lpcg_scu {int bit_idx; int /*<<< orphan*/  reg; scalar_t__ hw_gate; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int CLK_GATE_SCU_LPCG_HW_SEL ; 
 int CLK_GATE_SCU_LPCG_MASK ; 
 int CLK_GATE_SCU_LPCG_SW_SEL ; 
 int /*<<< orphan*/  imx_lpcg_scu_lock ; 
 int readl_relaxed (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct clk_lpcg_scu* to_clk_lpcg_scu (struct clk_hw*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int clk_lpcg_scu_enable(struct clk_hw *hw)
{
	struct clk_lpcg_scu *clk = to_clk_lpcg_scu(hw);
	unsigned long flags;
	u32 reg, val;

	spin_lock_irqsave(&imx_lpcg_scu_lock, flags);

	reg = readl_relaxed(clk->reg);
	reg &= ~(CLK_GATE_SCU_LPCG_MASK << clk->bit_idx);

	val = CLK_GATE_SCU_LPCG_SW_SEL;
	if (clk->hw_gate)
		val |= CLK_GATE_SCU_LPCG_HW_SEL;

	reg |= val << clk->bit_idx;
	writel(reg, clk->reg);

	spin_unlock_irqrestore(&imx_lpcg_scu_lock, flags);

	return 0;
}