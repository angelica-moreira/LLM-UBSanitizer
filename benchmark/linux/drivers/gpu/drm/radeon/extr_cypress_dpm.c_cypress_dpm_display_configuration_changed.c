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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cypress_program_display_gap (struct radeon_device*) ; 

void cypress_dpm_display_configuration_changed(struct radeon_device *rdev)
{
	cypress_program_display_gap(rdev);
}