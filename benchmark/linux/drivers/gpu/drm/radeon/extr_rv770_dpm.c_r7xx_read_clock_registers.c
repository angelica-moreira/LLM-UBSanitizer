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
struct radeon_device {scalar_t__ family; } ;

/* Variables and functions */
 scalar_t__ CHIP_RV710 ; 
 scalar_t__ CHIP_RV730 ; 
 scalar_t__ CHIP_RV740 ; 
 int /*<<< orphan*/  rv730_read_clock_registers (struct radeon_device*) ; 
 int /*<<< orphan*/  rv740_read_clock_registers (struct radeon_device*) ; 
 int /*<<< orphan*/  rv770_read_clock_registers (struct radeon_device*) ; 

__attribute__((used)) static void r7xx_read_clock_registers(struct radeon_device *rdev)
{
	if (rdev->family == CHIP_RV740)
		rv740_read_clock_registers(rdev);
	else if ((rdev->family == CHIP_RV730) || (rdev->family == CHIP_RV710))
		rv730_read_clock_registers(rdev);
	else
		rv770_read_clock_registers(rdev);
}