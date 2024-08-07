#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_8__ {int /*<<< orphan*/  mvdd_bootup_value; int /*<<< orphan*/  vddci_bootup_value; int /*<<< orphan*/  vddc_bootup_value; int /*<<< orphan*/  mclk_bootup_value; int /*<<< orphan*/  sclk_bootup_value; } ;
struct TYPE_6__ {int /*<<< orphan*/  mclk_table; int /*<<< orphan*/  sclk_table; } ;
struct smu7_hwmgr {scalar_t__ vddci_control; TYPE_3__ vbios_boot_state; TYPE_1__ dpm_table; } ;
struct pp_hwmgr {scalar_t__ smu_backend; scalar_t__ backend; } ;
struct TYPE_7__ {scalar_t__ MemoryBootLevel; scalar_t__ GraphicsBootLevel; } ;
struct iceland_smumgr {TYPE_2__ smc_state_table; } ;
struct TYPE_9__ {int /*<<< orphan*/  BootMVdd; int /*<<< orphan*/  BootVddci; int /*<<< orphan*/  BootVddc; scalar_t__ MemoryBootLevel; scalar_t__ GraphicsBootLevel; } ;
typedef  TYPE_4__ SMU71_Discrete_DpmTable ;

/* Variables and functions */
 scalar_t__ SMU7_VOLTAGE_CONTROL_NONE ; 
 int phm_find_boot_level (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 

__attribute__((used)) static int iceland_populate_smc_boot_level(struct pp_hwmgr *hwmgr,
			SMU71_Discrete_DpmTable *table)
{
	int result = 0;
	struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);
	struct iceland_smumgr *smu_data = (struct iceland_smumgr *)(hwmgr->smu_backend);
	table->GraphicsBootLevel = 0;
	table->MemoryBootLevel = 0;

	/* find boot level from dpm table*/
	result = phm_find_boot_level(&(data->dpm_table.sclk_table),
			data->vbios_boot_state.sclk_bootup_value,
			(uint32_t *)&(smu_data->smc_state_table.GraphicsBootLevel));

	if (0 != result) {
		smu_data->smc_state_table.GraphicsBootLevel = 0;
		pr_err("VBIOS did not find boot engine clock value in dependency table. Using Graphics DPM level 0!\n");
		result = 0;
	}

	result = phm_find_boot_level(&(data->dpm_table.mclk_table),
		data->vbios_boot_state.mclk_bootup_value,
		(uint32_t *)&(smu_data->smc_state_table.MemoryBootLevel));

	if (0 != result) {
		smu_data->smc_state_table.MemoryBootLevel = 0;
		pr_err("VBIOS did not find boot engine clock value in dependency table. Using Memory DPM level 0!\n");
		result = 0;
	}

	table->BootVddc = data->vbios_boot_state.vddc_bootup_value;
	if (SMU7_VOLTAGE_CONTROL_NONE == data->vddci_control)
		table->BootVddci = table->BootVddc;
	else
		table->BootVddci = data->vbios_boot_state.vddci_bootup_value;

	table->BootMVdd = data->vbios_boot_state.mvdd_bootup_value;

	return result;
}