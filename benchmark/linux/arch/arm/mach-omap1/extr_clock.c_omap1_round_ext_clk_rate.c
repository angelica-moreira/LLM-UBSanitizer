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
 int calc_ext_dsor (unsigned long) ; 

long omap1_round_ext_clk_rate(struct clk *clk, unsigned long rate)
{
	return 96000000 / calc_ext_dsor(rate);
}