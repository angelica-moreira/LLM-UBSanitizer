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
struct sun4i_tmds {int div_offset; } ;
struct clk_rate_request {unsigned long rate; unsigned long best_parent_rate; struct clk_hw* best_parent_hw; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ abs (unsigned long) ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int) ; 
 unsigned long clk_hw_round_rate (struct clk_hw*,unsigned long) ; 
 struct sun4i_tmds* hw_to_tmds (struct clk_hw*) ; 

__attribute__((used)) static int sun4i_tmds_determine_rate(struct clk_hw *hw,
				     struct clk_rate_request *req)
{
	struct sun4i_tmds *tmds = hw_to_tmds(hw);
	struct clk_hw *parent = NULL;
	unsigned long best_parent = 0;
	unsigned long rate = req->rate;
	int best_div = 1, best_half = 1;
	int i, j, p;

	/*
	 * We only consider PLL3, since the TCON is very likely to be
	 * clocked from it, and to have the same rate than our HDMI
	 * clock, so we should not need to do anything.
	 */

	for (p = 0; p < clk_hw_get_num_parents(hw); p++) {
		parent = clk_hw_get_parent_by_index(hw, p);
		if (!parent)
			continue;

		for (i = 1; i < 3; i++) {
			for (j = tmds->div_offset ?: 1;
			     j < (16 + tmds->div_offset); j++) {
				unsigned long ideal = rate * i * j;
				unsigned long rounded;

				rounded = clk_hw_round_rate(parent, ideal);

				if (rounded == ideal) {
					best_parent = rounded;
					best_half = i;
					best_div = j;
					goto out;
				}

				if (!best_parent ||
				    abs(rate - rounded / i / j) <
				    abs(rate - best_parent / best_half /
					best_div)) {
					best_parent = rounded;
					best_half = i;
					best_div = j;
				}
			}
		}
	}

	if (!parent)
		return -EINVAL;

out:
	req->rate = best_parent / best_half / best_div;
	req->best_parent_rate = best_parent;
	req->best_parent_hw = parent;

	return 0;
}