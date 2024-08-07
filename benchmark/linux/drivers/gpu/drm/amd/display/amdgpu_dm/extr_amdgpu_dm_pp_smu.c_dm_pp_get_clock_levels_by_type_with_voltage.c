#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct pp_clock_levels_with_voltage {int /*<<< orphan*/  member_0; } ;
struct dm_pp_clock_levels_with_voltage {int dummy; } ;
struct dc_context {struct amdgpu_device* driver_context; } ;
struct TYPE_6__ {TYPE_2__* ppt_funcs; } ;
struct TYPE_4__ {struct amd_pm_funcs* pp_funcs; void* pp_handle; } ;
struct amdgpu_device {TYPE_3__ smu; TYPE_1__ powerplay; } ;
struct amd_pm_funcs {int (* get_clock_by_type_with_voltage ) (void*,int /*<<< orphan*/ ,struct pp_clock_levels_with_voltage*) ;} ;
typedef  enum dm_pp_clock_type { ____Placeholder_dm_pp_clock_type } dm_pp_clock_type ;
struct TYPE_5__ {scalar_t__ get_clock_by_type_with_voltage; } ;

/* Variables and functions */
 int /*<<< orphan*/  dc_to_pp_clock_type (int) ; 
 int /*<<< orphan*/  pp_to_dc_clock_levels_with_voltage (struct pp_clock_levels_with_voltage*,struct dm_pp_clock_levels_with_voltage*,int) ; 
 scalar_t__ smu_get_clock_by_type_with_voltage (TYPE_3__*,int /*<<< orphan*/ ,struct pp_clock_levels_with_voltage*) ; 
 int stub1 (void*,int /*<<< orphan*/ ,struct pp_clock_levels_with_voltage*) ; 

bool dm_pp_get_clock_levels_by_type_with_voltage(
	const struct dc_context *ctx,
	enum dm_pp_clock_type clk_type,
	struct dm_pp_clock_levels_with_voltage *clk_level_info)
{
	struct amdgpu_device *adev = ctx->driver_context;
	void *pp_handle = adev->powerplay.pp_handle;
	struct pp_clock_levels_with_voltage pp_clk_info = {0};
	const struct amd_pm_funcs *pp_funcs = adev->powerplay.pp_funcs;
	int ret;

	if (pp_funcs && pp_funcs->get_clock_by_type_with_voltage) {
		ret = pp_funcs->get_clock_by_type_with_voltage(pp_handle,
						dc_to_pp_clock_type(clk_type),
						&pp_clk_info);
		if (ret)
			return false;
	} else if (adev->smu.ppt_funcs && adev->smu.ppt_funcs->get_clock_by_type_with_voltage) {
		if (smu_get_clock_by_type_with_voltage(&adev->smu,
						       dc_to_pp_clock_type(clk_type),
						       &pp_clk_info))
			return false;
	}

	pp_to_dc_clock_levels_with_voltage(&pp_clk_info, clk_level_info, clk_type);

	return true;
}