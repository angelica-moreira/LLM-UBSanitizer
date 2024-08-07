#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct clk_hw {int dummy; } ;
struct TYPE_2__ {long (* round_rate ) (struct clk_hw*,unsigned long,unsigned long*) ;} ;

/* Variables and functions */
 TYPE_1__ clk_divider_ops ; 
 long stub1 (struct clk_hw*,unsigned long,unsigned long*) ; 

__attribute__((used)) static long stm32f4_pll_div_round_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long *prate)
{
	return clk_divider_ops.round_rate(hw, rate, prate);
}