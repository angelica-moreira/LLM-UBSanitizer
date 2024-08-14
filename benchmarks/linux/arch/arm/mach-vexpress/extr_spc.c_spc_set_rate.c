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
struct clk_spc {int /*<<< orphan*/  cluster; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 struct clk_spc* to_clk_spc (struct clk_hw*) ; 
 int ve_spc_set_performance (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static int spc_set_rate(struct clk_hw *hw, unsigned long rate,
		unsigned long parent_rate)
{
	struct clk_spc *spc = to_clk_spc(hw);

	return ve_spc_set_performance(spc->cluster, rate / 1000);
}