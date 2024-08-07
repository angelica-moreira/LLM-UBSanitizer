#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ parent_clk; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_put (scalar_t__) ; 
 TYPE_1__ dss ; 

__attribute__((used)) static void dss_put_clocks(void)
{
	if (dss.parent_clk)
		clk_put(dss.parent_clk);
}