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
struct clk {scalar_t__ usage; int /*<<< orphan*/  (* set ) (struct clk*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct clk*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void clk_disable_unlocked(struct clk *clk)
{
	if (clk->set && (--clk->usage) == 0)
		clk->set(clk, 0);
}