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
struct clk {int (* activate ) (struct clk*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  clk_good (struct clk*) ; 
 int stub1 (struct clk*) ; 
 scalar_t__ unlikely (int) ; 

int clk_activate(struct clk *clk)
{
	if (unlikely(!clk_good(clk)))
		return -1;

	if (clk->activate)
		return clk->activate(clk);

	return -1;
}