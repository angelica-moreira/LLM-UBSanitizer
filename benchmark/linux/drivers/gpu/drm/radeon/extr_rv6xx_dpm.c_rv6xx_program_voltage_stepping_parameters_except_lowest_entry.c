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
struct TYPE_2__ {int /*<<< orphan*/ * vddc; } ;
struct rv6xx_power_info {TYPE_1__ hw; } ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int R600_PM_NUMBER_OF_VOLTAGE_LEVELS ; 
 struct rv6xx_power_info* rv6xx_get_pi (struct radeon_device*) ; 
 int /*<<< orphan*/  rv6xx_program_voltage_stepping_entry (struct radeon_device*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rv6xx_program_voltage_stepping_parameters_except_lowest_entry(struct radeon_device *rdev)
{
	struct rv6xx_power_info *pi = rv6xx_get_pi(rdev);
	int i;

	for (i = 1; i < R600_PM_NUMBER_OF_VOLTAGE_LEVELS; i++)
		rv6xx_program_voltage_stepping_entry(rdev, i,
						     pi->hw.vddc[i]);

}