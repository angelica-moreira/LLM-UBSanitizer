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
typedef  int u8 ;
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  CM_AUTOIDLE ; 
 int OMAP24XX_AUTO_DPLL_MASK ; 
 int OMAP24XX_AUTO_DPLL_SHIFT ; 
 int /*<<< orphan*/  PLL_MOD ; 
 int omap2_cm_read_mod_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap2_cm_write_mod_reg (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void _omap2xxx_set_dpll_autoidle(u8 m)
{
	u32 v;

	v = omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE);
	v &= ~OMAP24XX_AUTO_DPLL_MASK;
	v |= m << OMAP24XX_AUTO_DPLL_SHIFT;
	omap2_cm_write_mod_reg(v, PLL_MOD, CM_AUTOIDLE);
}