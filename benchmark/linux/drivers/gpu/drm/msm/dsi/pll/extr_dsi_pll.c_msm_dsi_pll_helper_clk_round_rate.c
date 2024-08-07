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
struct msm_dsi_pll {unsigned long min_rate; unsigned long max_rate; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 struct msm_dsi_pll* hw_clk_to_pll (struct clk_hw*) ; 

long msm_dsi_pll_helper_clk_round_rate(struct clk_hw *hw,
		unsigned long rate, unsigned long *parent_rate)
{
	struct msm_dsi_pll *pll = hw_clk_to_pll(hw);

	if      (rate < pll->min_rate)
		return  pll->min_rate;
	else if (rate > pll->max_rate)
		return  pll->max_rate;
	else
		return rate;
}