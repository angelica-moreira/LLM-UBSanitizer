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
 int /*<<< orphan*/  FDO_PWM_MODE_STATIC ; 
 int /*<<< orphan*/  PHM_PlatformCaps_MicrocodeFanControl ; 
 scalar_t__ PP_CAP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smu7_fan_ctrl_set_static_mode (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smu7_fan_ctrl_start_smc_fan_control (struct pp_hwmgr*) ; 

__attribute__((used)) static int smu7_thermal_start_smc_fan_control(struct pp_hwmgr *hwmgr)
{
/* If the fantable setup has failed we could have disabled
 * PHM_PlatformCaps_MicrocodeFanControl even after
 * this function was included in the table.
 * Make sure that we still think controlling the fan is OK.
*/
	if (PP_CAP(PHM_PlatformCaps_MicrocodeFanControl)) {
		smu7_fan_ctrl_start_smc_fan_control(hwmgr);
		smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
	}

	return 0;
}