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
typedef  int /*<<< orphan*/  u32 ;
struct pmic_wrapper {int dummy; } ;

/* Variables and functions */
 scalar_t__ PWRAP_GET_WACS_FSM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PWRAP_WACS2_RDATA ; 
 scalar_t__ PWRAP_WACS_FSM_WFVLDCLR ; 
 int /*<<< orphan*/  pwrap_readl (struct pmic_wrapper*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool pwrap_is_fsm_vldclr(struct pmic_wrapper *wrp)
{
	u32 val = pwrap_readl(wrp, PWRAP_WACS2_RDATA);

	return PWRAP_GET_WACS_FSM(val) == PWRAP_WACS_FSM_WFVLDCLR;
}