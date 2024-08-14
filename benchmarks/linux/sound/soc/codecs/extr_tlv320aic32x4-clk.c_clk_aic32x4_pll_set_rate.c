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
struct clk_hw {int dummy; } ;
struct clk_aic32x4_pll_muldiv {int dummy; } ;
struct clk_aic32x4 {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int clk_aic32x4_pll_calc_muldiv (struct clk_aic32x4_pll_muldiv*,unsigned long,unsigned long) ; 
 int clk_aic32x4_pll_set_muldiv (struct clk_aic32x4*,struct clk_aic32x4_pll_muldiv*) ; 
 struct clk_aic32x4* to_clk_aic32x4 (struct clk_hw*) ; 

__attribute__((used)) static int clk_aic32x4_pll_set_rate(struct clk_hw *hw,
			unsigned long rate,
			unsigned long parent_rate)
{
	struct clk_aic32x4 *pll = to_clk_aic32x4(hw);
	struct clk_aic32x4_pll_muldiv settings;
	int ret;

	ret = clk_aic32x4_pll_calc_muldiv(&settings, rate, parent_rate);
	if (ret < 0)
		return -EINVAL;

	return clk_aic32x4_pll_set_muldiv(pll, &settings);
}