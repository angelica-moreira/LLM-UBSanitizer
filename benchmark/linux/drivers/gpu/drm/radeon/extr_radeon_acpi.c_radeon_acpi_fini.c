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
struct radeon_device {int /*<<< orphan*/  acpi_nb; } ;

/* Variables and functions */
 int /*<<< orphan*/  unregister_acpi_notifier (int /*<<< orphan*/ *) ; 

void radeon_acpi_fini(struct radeon_device *rdev)
{
	unregister_acpi_notifier(&rdev->acpi_nb);
}