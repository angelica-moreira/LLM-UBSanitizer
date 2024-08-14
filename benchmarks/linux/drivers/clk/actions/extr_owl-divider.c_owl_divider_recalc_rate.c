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
struct owl_divider {int /*<<< orphan*/  div_hw; int /*<<< orphan*/  common; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 struct owl_divider* hw_to_owl_divider (struct clk_hw*) ; 
 unsigned long owl_divider_helper_recalc_rate (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static unsigned long owl_divider_recalc_rate(struct clk_hw *hw,
					  unsigned long parent_rate)
{
	struct owl_divider *div = hw_to_owl_divider(hw);

	return owl_divider_helper_recalc_rate(&div->common,
					      &div->div_hw, parent_rate);
}