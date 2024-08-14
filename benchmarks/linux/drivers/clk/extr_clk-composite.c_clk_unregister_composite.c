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
struct clk_composite {int dummy; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 struct clk_hw* __clk_get_hw (struct clk*) ; 
 int /*<<< orphan*/  clk_unregister (struct clk*) ; 
 int /*<<< orphan*/  kfree (struct clk_composite*) ; 
 struct clk_composite* to_clk_composite (struct clk_hw*) ; 

void clk_unregister_composite(struct clk *clk)
{
	struct clk_composite *composite;
	struct clk_hw *hw;

	hw = __clk_get_hw(clk);
	if (!hw)
		return;

	composite = to_clk_composite(hw);

	clk_unregister(clk);
	kfree(composite);
}