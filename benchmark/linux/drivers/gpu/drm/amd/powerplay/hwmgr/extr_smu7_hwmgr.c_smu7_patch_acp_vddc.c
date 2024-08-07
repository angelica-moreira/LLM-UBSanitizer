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
typedef  size_t uint16_t ;
struct smu7_hwmgr {int /*<<< orphan*/  vddc_leakage; } ;
struct pp_hwmgr {scalar_t__ backend; } ;
struct phm_acp_clock_voltage_dependency_table {size_t count; TYPE_1__* entries; } ;
struct TYPE_2__ {int /*<<< orphan*/  v; } ;

/* Variables and functions */
 int /*<<< orphan*/  smu7_patch_ppt_v0_with_vdd_leakage (struct pp_hwmgr*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int smu7_patch_acp_vddc(struct pp_hwmgr *hwmgr,
				  struct phm_acp_clock_voltage_dependency_table *tab)
{
	uint16_t i;
	struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);

	if (tab)
		for (i = 0; i < tab->count; i++)
			smu7_patch_ppt_v0_with_vdd_leakage(hwmgr, &tab->entries[i].v,
					&data->vddc_leakage);

	return 0;
}