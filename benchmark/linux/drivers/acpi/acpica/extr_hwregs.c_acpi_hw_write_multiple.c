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
typedef  int /*<<< orphan*/  u32 ;
struct acpi_generic_address {scalar_t__ address; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_hw_write (int /*<<< orphan*/ ,struct acpi_generic_address*) ; 

__attribute__((used)) static acpi_status
acpi_hw_write_multiple(u32 value,
		       struct acpi_generic_address *register_a,
		       struct acpi_generic_address *register_b)
{
	acpi_status status;

	/* The first register is always required */

	status = acpi_hw_write(value, register_a);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	/*
	 * Second register is optional
	 *
	 * No bit shifting or clearing is necessary, because of how the PM1
	 * registers are defined in the ACPI specification:
	 *
	 * "Although the bits can be split between the two register blocks (each
	 * register block has a unique pointer within the FADT), the bit positions
	 * are maintained. The register block with unimplemented bits (that is,
	 * those implemented in the other register block) always returns zeros,
	 * and writes have no side effects"
	 */
	if (register_b->address) {
		status = acpi_hw_write(value, register_b);
	}

	return (status);
}