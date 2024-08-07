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
struct sun4i_dclk {int /*<<< orphan*/  regmap; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SUN4I_TCON0_DCLK_GATE_BIT ; 
 int /*<<< orphan*/  SUN4I_TCON0_DCLK_REG ; 
 struct sun4i_dclk* hw_to_dclk (struct clk_hw*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sun4i_dclk_enable(struct clk_hw *hw)
{
	struct sun4i_dclk *dclk = hw_to_dclk(hw);

	return regmap_update_bits(dclk->regmap, SUN4I_TCON0_DCLK_REG,
				  BIT(SUN4I_TCON0_DCLK_GATE_BIT),
				  BIT(SUN4I_TCON0_DCLK_GATE_BIT));
}