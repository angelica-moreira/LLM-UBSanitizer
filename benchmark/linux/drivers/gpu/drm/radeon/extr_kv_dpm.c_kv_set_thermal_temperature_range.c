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
typedef  int u32 ;
struct TYPE_4__ {int min_temp; int max_temp; } ;
struct TYPE_5__ {TYPE_1__ thermal; } ;
struct TYPE_6__ {TYPE_2__ dpm; } ;
struct radeon_device {TYPE_3__ pm; } ;

/* Variables and functions */
 int /*<<< orphan*/  CG_THERMAL_INT_CTRL ; 
 int DIG_THERM_INTH (int) ; 
 int DIG_THERM_INTH_MASK ; 
 int DIG_THERM_INTL (int) ; 
 int DIG_THERM_INTL_MASK ; 
 int /*<<< orphan*/  DRM_ERROR (char*,int,int) ; 
 int EINVAL ; 
 int RREG32_SMC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32_SMC (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int kv_set_thermal_temperature_range(struct radeon_device *rdev,
					    int min_temp, int max_temp)
{
	int low_temp = 0 * 1000;
	int high_temp = 255 * 1000;
	u32 tmp;

	if (low_temp < min_temp)
		low_temp = min_temp;
	if (high_temp > max_temp)
		high_temp = max_temp;
	if (high_temp < low_temp) {
		DRM_ERROR("invalid thermal range: %d - %d\n", low_temp, high_temp);
		return -EINVAL;
	}

	tmp = RREG32_SMC(CG_THERMAL_INT_CTRL);
	tmp &= ~(DIG_THERM_INTH_MASK | DIG_THERM_INTL_MASK);
	tmp |= (DIG_THERM_INTH(49 + (high_temp / 1000)) |
		DIG_THERM_INTL(49 + (low_temp / 1000)));
	WREG32_SMC(CG_THERMAL_INT_CTRL, tmp);

	rdev->pm.dpm.thermal.min_temp = low_temp;
	rdev->pm.dpm.thermal.max_temp = high_temp;

	return 0;
}