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
struct clockdomain {int /*<<< orphan*/  clkdm_offs; int /*<<< orphan*/  cm_inst; } ;

/* Variables and functions */
 int /*<<< orphan*/  am33xx_cm_clkdm_enable_hwsup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void am33xx_clkdm_allow_idle(struct clockdomain *clkdm)
{
	am33xx_cm_clkdm_enable_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
}