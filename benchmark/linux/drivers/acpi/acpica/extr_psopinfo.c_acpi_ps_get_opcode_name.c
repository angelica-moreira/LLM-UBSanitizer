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
typedef  int /*<<< orphan*/  u16 ;
struct acpi_opcode_info {char const* name; } ;

/* Variables and functions */
 struct acpi_opcode_info* acpi_ps_get_opcode_info (int /*<<< orphan*/ ) ; 

const char *acpi_ps_get_opcode_name(u16 opcode)
{
#if defined(ACPI_DISASSEMBLER) || defined (ACPI_DEBUG_OUTPUT)

	const struct acpi_opcode_info *op;

	op = acpi_ps_get_opcode_info(opcode);

	/* Always guaranteed to return a valid pointer */

	return (op->name);

#else
	return ("OpcodeName unavailable");

#endif
}