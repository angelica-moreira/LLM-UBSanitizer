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
struct csi_state {int /*<<< orphan*/  clks; int /*<<< orphan*/  num_clks; } ;

/* Variables and functions */
 int clk_bulk_prepare_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mipi_csis_clk_enable(struct csi_state *state)
{
	return clk_bulk_prepare_enable(state->num_clks, state->clks);
}