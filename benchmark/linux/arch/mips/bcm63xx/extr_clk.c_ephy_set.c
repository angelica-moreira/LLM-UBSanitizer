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
 scalar_t__ BCMCPU_IS_3368 () ; 
 scalar_t__ BCMCPU_IS_6358 () ; 
 int /*<<< orphan*/  CKCTL_6358_EPHY_EN ; 
 int /*<<< orphan*/  bcm_hwclock_set (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void ephy_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_3368() || BCMCPU_IS_6358())
		bcm_hwclock_set(CKCTL_6358_EPHY_EN, enable);
}