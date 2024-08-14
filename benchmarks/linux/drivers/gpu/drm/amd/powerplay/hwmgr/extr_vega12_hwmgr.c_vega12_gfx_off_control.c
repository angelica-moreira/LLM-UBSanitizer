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
 int vega12_disable_gfx_off (struct pp_hwmgr*) ; 
 int vega12_enable_gfx_off (struct pp_hwmgr*) ; 

__attribute__((used)) static int vega12_gfx_off_control(struct pp_hwmgr *hwmgr, bool enable)
{
	if (enable)
		return vega12_enable_gfx_off(hwmgr);
	else
		return vega12_disable_gfx_off(hwmgr);
}