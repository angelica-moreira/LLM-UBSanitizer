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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct clk_mux {int shift; int mask; int /*<<< orphan*/  flags; int /*<<< orphan*/  table; int /*<<< orphan*/  reg; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_mux_val_to_index (struct clk_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int readl (int /*<<< orphan*/ ) ; 
 struct clk_mux* to_clk_mux (struct clk_hw*) ; 

__attribute__((used)) static u8 m10v_mux_get_parent(struct clk_hw *hw)
{
	struct clk_mux *mux = to_clk_mux(hw);
	u32 val;

	val = readl(mux->reg) >> mux->shift;
	val &= mux->mask;

	return clk_mux_val_to_index(hw, mux->table, mux->flags, val);
}