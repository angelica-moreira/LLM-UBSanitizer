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
typedef  size_t uint32_t ;
struct smu10_voltage_dependency_table {scalar_t__ count; TYPE_2__* entries; } ;
struct smu10_clock_voltage_information {struct smu10_voltage_dependency_table* vdd_dep_on_dppclk; struct smu10_voltage_dependency_table* vdd_dep_on_phyclk; struct smu10_voltage_dependency_table* vdd_dep_on_dispclk; struct smu10_voltage_dependency_table* vdd_dep_on_dcefclk; struct smu10_voltage_dependency_table* vdd_dep_on_fclk; struct smu10_voltage_dependency_table* vdd_dep_on_mclk; } ;
struct smu10_hwmgr {struct smu10_clock_voltage_information clock_vol_info; } ;
struct pp_hwmgr {scalar_t__ backend; } ;
struct pp_clock_levels_with_latency {scalar_t__ num_levels; TYPE_1__* data; } ;
typedef  enum amd_pp_clock_type { ____Placeholder_amd_pp_clock_type } amd_pp_clock_type ;
struct TYPE_4__ {int clk; } ;
struct TYPE_3__ {int clocks_in_khz; int /*<<< orphan*/  latency_in_us; } ;

/* Variables and functions */
 int EINVAL ; 
#define  amd_pp_dcf_clock 133 
#define  amd_pp_disp_clock 132 
#define  amd_pp_dpp_clock 131 
#define  amd_pp_f_clock 130 
#define  amd_pp_mem_clock 129 
#define  amd_pp_phy_clock 128 
 int /*<<< orphan*/  smu10_get_mem_latency (struct pp_hwmgr*,int) ; 

__attribute__((used)) static int smu10_get_clock_by_type_with_latency(struct pp_hwmgr *hwmgr,
		enum amd_pp_clock_type type,
		struct pp_clock_levels_with_latency *clocks)
{
	uint32_t i;
	struct smu10_hwmgr *smu10_data = (struct smu10_hwmgr *)(hwmgr->backend);
	struct smu10_clock_voltage_information *pinfo = &(smu10_data->clock_vol_info);
	struct smu10_voltage_dependency_table *pclk_vol_table;
	bool latency_required = false;

	if (pinfo == NULL)
		return -EINVAL;

	switch (type) {
	case amd_pp_mem_clock:
		pclk_vol_table = pinfo->vdd_dep_on_mclk;
		latency_required = true;
		break;
	case amd_pp_f_clock:
		pclk_vol_table = pinfo->vdd_dep_on_fclk;
		latency_required = true;
		break;
	case amd_pp_dcf_clock:
		pclk_vol_table = pinfo->vdd_dep_on_dcefclk;
		break;
	case amd_pp_disp_clock:
		pclk_vol_table = pinfo->vdd_dep_on_dispclk;
		break;
	case amd_pp_phy_clock:
		pclk_vol_table = pinfo->vdd_dep_on_phyclk;
		break;
	case amd_pp_dpp_clock:
		pclk_vol_table = pinfo->vdd_dep_on_dppclk;
		break;
	default:
		return -EINVAL;
	}

	if (pclk_vol_table == NULL || pclk_vol_table->count == 0)
		return -EINVAL;

	clocks->num_levels = 0;
	for (i = 0; i < pclk_vol_table->count; i++) {
		clocks->data[i].clocks_in_khz = pclk_vol_table->entries[i].clk * 10;
		clocks->data[i].latency_in_us = latency_required ?
						smu10_get_mem_latency(hwmgr,
						pclk_vol_table->entries[i].clk) :
						0;
		clocks->num_levels++;
	}

	return 0;
}