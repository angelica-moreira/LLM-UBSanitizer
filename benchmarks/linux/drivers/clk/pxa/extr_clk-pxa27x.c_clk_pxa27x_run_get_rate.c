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
 int /*<<< orphan*/  CCSR ; 
 unsigned long CCSR_N2_MASK ; 
 unsigned long CCSR_N2_SHIFT ; 
 unsigned long readl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long clk_pxa27x_run_get_rate(struct clk_hw *hw,
					     unsigned long parent_rate)
{
	unsigned long ccsr = readl(CCSR);
	unsigned int n2 = (ccsr & CCSR_N2_MASK) >> CCSR_N2_SHIFT;

	return (parent_rate / n2) * 2;
}