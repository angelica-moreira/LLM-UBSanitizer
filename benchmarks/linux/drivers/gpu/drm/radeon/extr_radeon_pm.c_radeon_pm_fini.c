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
struct TYPE_2__ {scalar_t__ pm_method; } ;
struct radeon_device {TYPE_1__ pm; } ;

/* Variables and functions */
 scalar_t__ PM_METHOD_DPM ; 
 int /*<<< orphan*/  radeon_pm_fini_dpm (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_pm_fini_old (struct radeon_device*) ; 

void radeon_pm_fini(struct radeon_device *rdev)
{
	if (rdev->pm.pm_method == PM_METHOD_DPM)
		radeon_pm_fini_dpm(rdev);
	else
		radeon_pm_fini_old(rdev);
}