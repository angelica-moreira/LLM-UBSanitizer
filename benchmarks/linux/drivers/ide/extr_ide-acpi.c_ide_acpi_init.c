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

/* Variables and functions */
 int /*<<< orphan*/  dmi_check_system (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ide_acpi_dmi_table ; 

int ide_acpi_init(void)
{
	dmi_check_system(ide_acpi_dmi_table);
	return 0;
}