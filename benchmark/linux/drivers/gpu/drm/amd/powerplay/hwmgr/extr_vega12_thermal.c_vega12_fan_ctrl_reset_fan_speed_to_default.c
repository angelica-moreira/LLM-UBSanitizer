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
 int vega12_fan_ctrl_start_smc_fan_control (struct pp_hwmgr*) ; 

int vega12_fan_ctrl_reset_fan_speed_to_default(struct pp_hwmgr *hwmgr)
{
	return vega12_fan_ctrl_start_smc_fan_control(hwmgr);
}