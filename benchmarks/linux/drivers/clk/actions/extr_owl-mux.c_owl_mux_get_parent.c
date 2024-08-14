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
struct owl_mux {int /*<<< orphan*/  mux_hw; int /*<<< orphan*/  common; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 struct owl_mux* hw_to_owl_mux (struct clk_hw*) ; 
 int /*<<< orphan*/  owl_mux_helper_get_parent (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static u8 owl_mux_get_parent(struct clk_hw *hw)
{
	struct owl_mux *mux = hw_to_owl_mux(hw);

	return owl_mux_helper_get_parent(&mux->common, &mux->mux_hw);
}