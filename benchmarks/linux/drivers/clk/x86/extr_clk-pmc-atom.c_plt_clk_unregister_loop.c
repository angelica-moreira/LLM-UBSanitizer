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
struct clk_plt_data {int /*<<< orphan*/ * clks; } ;

/* Variables and functions */
 int /*<<< orphan*/  plt_clk_unregister (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void plt_clk_unregister_loop(struct clk_plt_data *data,
				    unsigned int i)
{
	while (i--)
		plt_clk_unregister(data->clks[i]);
}