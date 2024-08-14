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
struct clk {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  api_ck_p ; 
 int /*<<< orphan*/  omap1_clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap1_clk_disable_generic (struct clk*) ; 
 scalar_t__ omap1_clk_enable (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void omap1_clk_disable_dsp_domain(struct clk *clk)
{
	if (omap1_clk_enable(api_ck_p) == 0) {
		omap1_clk_disable_generic(clk);
		omap1_clk_disable(api_ck_p);
	}
}