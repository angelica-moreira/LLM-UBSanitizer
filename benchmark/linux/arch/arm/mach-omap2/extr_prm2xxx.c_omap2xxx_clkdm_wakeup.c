#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* ptr; } ;
struct clockdomain {TYPE_2__ pwrdm; } ;
struct TYPE_3__ {int /*<<< orphan*/  prcm_offs; } ;

/* Variables and functions */
 int /*<<< orphan*/  OMAP24XX_FORCESTATE_MASK ; 
 int /*<<< orphan*/  OMAP2_PM_PWSTCTRL ; 
 int /*<<< orphan*/  omap2_prm_clear_mod_reg_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int omap2xxx_clkdm_wakeup(struct clockdomain *clkdm)
{
	omap2_prm_clear_mod_reg_bits(OMAP24XX_FORCESTATE_MASK,
				     clkdm->pwrdm.ptr->prcm_offs,
				     OMAP2_PM_PWSTCTRL);
	return 0;
}