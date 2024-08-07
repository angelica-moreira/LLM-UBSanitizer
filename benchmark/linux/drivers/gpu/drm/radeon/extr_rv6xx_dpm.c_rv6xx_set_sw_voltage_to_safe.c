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
typedef  scalar_t__ u16 ;
struct TYPE_2__ {scalar_t__ vddc; } ;
struct rv6xx_ps {TYPE_1__ low; } ;
struct radeon_ps {int dummy; } ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GENERAL_PWRMGT ; 
 int /*<<< orphan*/  R600_POWER_LEVEL_CTXSW ; 
 int /*<<< orphan*/  SW_GPIO_INDEX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SW_GPIO_INDEX_MASK ; 
 int /*<<< orphan*/  WREG32_P (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rv6xx_ps* rv6xx_get_ps (struct radeon_ps*) ; 
 int /*<<< orphan*/  rv6xx_program_voltage_stepping_entry (struct radeon_device*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void rv6xx_set_sw_voltage_to_safe(struct radeon_device *rdev,
					 struct radeon_ps *new_ps,
					 struct radeon_ps *old_ps)
{
	struct rv6xx_ps *new_state = rv6xx_get_ps(new_ps);
	struct rv6xx_ps *old_state = rv6xx_get_ps(old_ps);
	u16 safe_voltage;

	safe_voltage = (new_state->low.vddc >= old_state->low.vddc) ?
		new_state->low.vddc : old_state->low.vddc;

	rv6xx_program_voltage_stepping_entry(rdev, R600_POWER_LEVEL_CTXSW,
					     safe_voltage);

	WREG32_P(GENERAL_PWRMGT, SW_GPIO_INDEX(R600_POWER_LEVEL_CTXSW),
		 ~SW_GPIO_INDEX_MASK);
}