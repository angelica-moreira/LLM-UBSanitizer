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
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  OMAP34XX_CLKSTCTRL_ENABLE_AUTO ; 
 int /*<<< orphan*/  _clktrctrl_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void am33xx_cm_clkdm_enable_hwsup(u16 inst, u16 cdoffs)
{
	_clktrctrl_write(OMAP34XX_CLKSTCTRL_ENABLE_AUTO, inst, cdoffs);
}