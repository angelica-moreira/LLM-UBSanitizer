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
struct clk_hw {int dummy; } ;
struct clk_divider_gate {int cached_val; } ;
struct clk_divider {int shift; int /*<<< orphan*/  lock; int /*<<< orphan*/  reg; int /*<<< orphan*/  width; int /*<<< orphan*/  flags; int /*<<< orphan*/  table; } ;

/* Variables and functions */
 int clk_div_mask (int /*<<< orphan*/ ) ; 
 scalar_t__ clk_hw_is_enabled (struct clk_hw*) ; 
 int divider_get_val (unsigned long,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 
 struct clk_divider* to_clk_divider (struct clk_hw*) ; 
 struct clk_divider_gate* to_clk_divider_gate (struct clk_hw*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int clk_divider_gate_set_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long parent_rate)
{
	struct clk_divider_gate *div_gate = to_clk_divider_gate(hw);
	struct clk_divider *div = to_clk_divider(hw);
	unsigned long flags = 0;
	int value;
	u32 val;

	value = divider_get_val(rate, parent_rate, div->table,
				div->width, div->flags);
	if (value < 0)
		return value;

	spin_lock_irqsave(div->lock, flags);

	if (clk_hw_is_enabled(hw)) {
		val = readl(div->reg);
		val &= ~(clk_div_mask(div->width) << div->shift);
		val |= (u32)value << div->shift;
		writel(val, div->reg);
	} else {
		div_gate->cached_val = value;
	}

	spin_unlock_irqrestore(div->lock, flags);

	return 0;
}