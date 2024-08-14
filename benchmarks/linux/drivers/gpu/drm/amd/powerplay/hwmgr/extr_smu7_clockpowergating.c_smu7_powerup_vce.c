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
struct pp_hwmgr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PPSMC_MSG_VCEPowerON ; 
 scalar_t__ phm_cf_want_vce_power_gating (struct pp_hwmgr*) ; 
 int smum_send_msg_to_smc (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int smu7_powerup_vce(struct pp_hwmgr *hwmgr)
{
	if (phm_cf_want_vce_power_gating(hwmgr))
		return smum_send_msg_to_smc(hwmgr,
				PPSMC_MSG_VCEPowerON);
	return 0;
}