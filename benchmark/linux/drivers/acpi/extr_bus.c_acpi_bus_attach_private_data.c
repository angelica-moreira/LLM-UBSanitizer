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
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int /*<<< orphan*/  acpi_attach_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  acpi_bus_private_data_handler ; 
 int /*<<< orphan*/  acpi_handle_debug (int /*<<< orphan*/ ,char*) ; 

int acpi_bus_attach_private_data(acpi_handle handle, void *data)
{
	acpi_status status;

	status = acpi_attach_data(handle,
			acpi_bus_private_data_handler, data);
	if (ACPI_FAILURE(status)) {
		acpi_handle_debug(handle, "Error attaching device data\n");
		return -ENODEV;
	}

	return 0;
}