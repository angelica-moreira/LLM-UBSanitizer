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
typedef  int u32 ;
struct otg_fsm {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  otgsc; } ;

/* Variables and functions */
 int OTGSC_CTRL_DATA_PULSING ; 
 int OTGSC_INTSTS_MASK ; 
 int fsl_readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fsl_writel (int,int /*<<< orphan*/ *) ; 
 TYPE_1__* usb_dr_regs ; 

void fsl_otg_loc_conn(struct otg_fsm *fsm, int on)
{
	u32 tmp;

	tmp = fsl_readl(&usb_dr_regs->otgsc) & ~OTGSC_INTSTS_MASK;

	if (on)
		tmp |= OTGSC_CTRL_DATA_PULSING;
	else
		tmp &= ~OTGSC_CTRL_DATA_PULSING;

	fsl_writel(tmp, &usb_dr_regs->otgsc);
}