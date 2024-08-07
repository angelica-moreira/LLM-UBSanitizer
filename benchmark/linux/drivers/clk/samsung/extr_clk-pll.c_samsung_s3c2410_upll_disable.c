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

/* Variables and functions */
 int /*<<< orphan*/  samsung_s3c2410_pll_enable (struct clk_hw*,int,int) ; 

__attribute__((used)) static void samsung_s3c2410_upll_disable(struct clk_hw *hw)
{
	samsung_s3c2410_pll_enable(hw, 7, false);
}