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
struct clk {int /*<<< orphan*/  core; } ;

/* Variables and functions */
 scalar_t__ IS_ERR_OR_NULL (struct clk*) ; 
 int /*<<< orphan*/  clk_core_unprepare_lock (int /*<<< orphan*/ ) ; 

void clk_unprepare(struct clk *clk)
{
	if (IS_ERR_OR_NULL(clk))
		return;

	clk_core_unprepare_lock(clk->core);
}