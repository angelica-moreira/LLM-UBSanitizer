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
struct clk_hw {int dummy; } ;
struct clk_dto {int /*<<< orphan*/  src_offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  clkc_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct clk_dto* to_dtoclk (struct clk_hw*) ; 

__attribute__((used)) static int dto_clk_set_parent(struct clk_hw *hw, u8 index)
{
	struct clk_dto *clk = to_dtoclk(hw);

	clkc_writel(index, clk->src_offset);
	return 0;
}