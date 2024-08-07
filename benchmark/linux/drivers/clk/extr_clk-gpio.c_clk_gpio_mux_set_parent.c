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
struct clk_gpio {int /*<<< orphan*/  gpiod; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct clk_gpio* to_clk_gpio (struct clk_hw*) ; 

__attribute__((used)) static int clk_gpio_mux_set_parent(struct clk_hw *hw, u8 index)
{
	struct clk_gpio *clk = to_clk_gpio(hw);

	gpiod_set_value_cansleep(clk->gpiod, index);

	return 0;
}