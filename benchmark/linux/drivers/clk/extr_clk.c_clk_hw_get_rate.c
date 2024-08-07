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
struct clk_hw {int /*<<< orphan*/  core; } ;

/* Variables and functions */
 unsigned long clk_core_get_rate_nolock (int /*<<< orphan*/ ) ; 

unsigned long clk_hw_get_rate(const struct clk_hw *hw)
{
	return clk_core_get_rate_nolock(hw->core);
}