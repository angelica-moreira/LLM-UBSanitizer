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
struct owl_composite {int /*<<< orphan*/  mux_hw; int /*<<< orphan*/  common; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 struct owl_composite* hw_to_owl_comp (struct clk_hw*) ; 
 int owl_mux_helper_set_parent (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int owl_comp_set_parent(struct clk_hw *hw, u8 index)
{
	struct owl_composite *comp = hw_to_owl_comp(hw);

	return owl_mux_helper_set_parent(&comp->common, &comp->mux_hw, index);
}