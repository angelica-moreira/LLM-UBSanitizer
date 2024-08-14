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
typedef  int /*<<< orphan*/  u32 ;
struct mmp_clk_mix_reg_info {int /*<<< orphan*/  shift_mux; int /*<<< orphan*/  width_mux; int /*<<< orphan*/  reg_clk_sel; int /*<<< orphan*/  reg_clk_ctrl; } ;
struct mmp_clk_mix {scalar_t__ type; struct mmp_clk_mix_reg_info reg_info; scalar_t__ lock; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MMP_CLK_BITS_GET_VAL (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ MMP_CLK_MIX_TYPE_V1 ; 
 scalar_t__ MMP_CLK_MIX_TYPE_V2 ; 
 int /*<<< orphan*/  _get_mux (struct mmp_clk_mix*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (scalar_t__,unsigned long) ; 
 struct mmp_clk_mix* to_clk_mix (struct clk_hw*) ; 

__attribute__((used)) static u8 mmp_clk_mix_get_parent(struct clk_hw *hw)
{
	struct mmp_clk_mix *mix = to_clk_mix(hw);
	struct mmp_clk_mix_reg_info *ri = &mix->reg_info;
	unsigned long flags = 0;
	u32 mux_div = 0;
	u8 width, shift;
	u32 mux_val;

	if (mix->lock)
		spin_lock_irqsave(mix->lock, flags);

	if (mix->type == MMP_CLK_MIX_TYPE_V1
		|| mix->type == MMP_CLK_MIX_TYPE_V2)
		mux_div = readl(ri->reg_clk_ctrl);
	else
		mux_div = readl(ri->reg_clk_sel);

	if (mix->lock)
		spin_unlock_irqrestore(mix->lock, flags);

	width = mix->reg_info.width_mux;
	shift = mix->reg_info.shift_mux;

	mux_val = MMP_CLK_BITS_GET_VAL(mux_div, width, shift);

	return _get_mux(mix, mux_val);
}