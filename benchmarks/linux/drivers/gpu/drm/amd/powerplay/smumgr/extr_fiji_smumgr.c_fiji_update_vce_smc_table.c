#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
struct TYPE_7__ {int /*<<< orphan*/  platformCaps; } ;
struct pp_hwmgr {TYPE_3__ platform_descriptor; int /*<<< orphan*/  device; scalar_t__ pptable; scalar_t__ smu_backend; } ;
struct phm_ppt_v1_information {TYPE_1__* mm_dep_table; } ;
struct TYPE_8__ {int VceBootLevel; } ;
struct TYPE_6__ {int dpm_table_start; } ;
struct fiji_smumgr {TYPE_4__ smc_state_table; TYPE_2__ smu7_data; } ;
struct TYPE_5__ {int count; } ;

/* Variables and functions */
 int /*<<< orphan*/  CGS_IND_REG__SMC ; 
 int /*<<< orphan*/  PHM_PlatformCaps_StablePState ; 
 int /*<<< orphan*/  PPSMC_MSG_VCEDPM_SetEnabledMask ; 
 int /*<<< orphan*/  SMU73_Discrete_DpmTable ; 
 int /*<<< orphan*/  VceBootLevel ; 
 int cgs_read_ind_register (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cgs_write_ind_register (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int offsetof (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ phm_cap_enabled (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smum_send_msg_to_smc_with_parameter (struct pp_hwmgr*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int fiji_update_vce_smc_table(struct pp_hwmgr *hwmgr)
{
	struct fiji_smumgr *smu_data = (struct fiji_smumgr *)(hwmgr->smu_backend);
	uint32_t mm_boot_level_offset, mm_boot_level_value;
	struct phm_ppt_v1_information *table_info =
			(struct phm_ppt_v1_information *)(hwmgr->pptable);

	if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
					PHM_PlatformCaps_StablePState))
		smu_data->smc_state_table.VceBootLevel =
			(uint8_t) (table_info->mm_dep_table->count - 1);
	else
		smu_data->smc_state_table.VceBootLevel = 0;

	mm_boot_level_offset = smu_data->smu7_data.dpm_table_start +
					offsetof(SMU73_Discrete_DpmTable, VceBootLevel);
	mm_boot_level_offset /= 4;
	mm_boot_level_offset *= 4;
	mm_boot_level_value = cgs_read_ind_register(hwmgr->device,
			CGS_IND_REG__SMC, mm_boot_level_offset);
	mm_boot_level_value &= 0xFF00FFFF;
	mm_boot_level_value |= smu_data->smc_state_table.VceBootLevel << 16;
	cgs_write_ind_register(hwmgr->device,
			CGS_IND_REG__SMC, mm_boot_level_offset, mm_boot_level_value);

	if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_StablePState))
		smum_send_msg_to_smc_with_parameter(hwmgr,
				PPSMC_MSG_VCEDPM_SetEnabledMask,
				(uint32_t)1 << smu_data->smc_state_table.VceBootLevel);
	return 0;
}