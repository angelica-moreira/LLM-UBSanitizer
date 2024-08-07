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
struct ac100_clkout {int /*<<< orphan*/  offset; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC100_CLKOUT_EN ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ac100_clkout* to_ac100_clkout (struct clk_hw*) ; 

__attribute__((used)) static int ac100_clkout_prepare(struct clk_hw *hw)
{
	struct ac100_clkout *clk = to_ac100_clkout(hw);

	return regmap_update_bits(clk->regmap, clk->offset, AC100_CLKOUT_EN,
				  AC100_CLKOUT_EN);
}