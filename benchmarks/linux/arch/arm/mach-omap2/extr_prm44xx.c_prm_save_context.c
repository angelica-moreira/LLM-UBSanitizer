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
struct TYPE_4__ {int /*<<< orphan*/  pm_ctrl; int /*<<< orphan*/  mask; } ;
struct TYPE_3__ {void* pm_ctrl; void* irq_enable; } ;

/* Variables and functions */
 int /*<<< orphan*/  AM43XX_PRM_DEVICE_INST ; 
 int /*<<< orphan*/  AM43XX_PRM_OCP_SOCKET_INST ; 
 TYPE_2__ omap4_prcm_irq_setup ; 
 void* omap4_prm_read_inst_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ omap_prm_context ; 

void prm_save_context(void)
{
	omap_prm_context.irq_enable =
			omap4_prm_read_inst_reg(AM43XX_PRM_OCP_SOCKET_INST,
						omap4_prcm_irq_setup.mask);

	omap_prm_context.pm_ctrl =
			omap4_prm_read_inst_reg(AM43XX_PRM_DEVICE_INST,
						omap4_prcm_irq_setup.pm_ctrl);
}