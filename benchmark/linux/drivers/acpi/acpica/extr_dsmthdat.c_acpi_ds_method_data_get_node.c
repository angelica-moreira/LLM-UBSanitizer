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
typedef  int u8 ;
typedef  size_t u32 ;
struct acpi_walk_state {struct acpi_namespace_node* arguments; struct acpi_namespace_node* local_variables; } ;
struct acpi_namespace_node {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 size_t ACPI_METHOD_MAX_ARG ; 
 size_t ACPI_METHOD_MAX_LOCAL ; 
#define  ACPI_REFCLASS_ARG 129 
#define  ACPI_REFCLASS_LOCAL 128 
 int /*<<< orphan*/  AE_AML_INVALID_INDEX ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AE_TYPE ; 
 int /*<<< orphan*/  ds_method_data_get_node ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

acpi_status
acpi_ds_method_data_get_node(u8 type,
			     u32 index,
			     struct acpi_walk_state *walk_state,
			     struct acpi_namespace_node **node)
{
	ACPI_FUNCTION_TRACE(ds_method_data_get_node);

	/*
	 * Method Locals and Arguments are supported
	 */
	switch (type) {
	case ACPI_REFCLASS_LOCAL:

		if (index > ACPI_METHOD_MAX_LOCAL) {
			ACPI_ERROR((AE_INFO,
				    "Local index %u is invalid (max %u)",
				    index, ACPI_METHOD_MAX_LOCAL));
			return_ACPI_STATUS(AE_AML_INVALID_INDEX);
		}

		/* Return a pointer to the pseudo-node */

		*node = &walk_state->local_variables[index];
		break;

	case ACPI_REFCLASS_ARG:

		if (index > ACPI_METHOD_MAX_ARG) {
			ACPI_ERROR((AE_INFO,
				    "Arg index %u is invalid (max %u)",
				    index, ACPI_METHOD_MAX_ARG));
			return_ACPI_STATUS(AE_AML_INVALID_INDEX);
		}

		/* Return a pointer to the pseudo-node */

		*node = &walk_state->arguments[index];
		break;

	default:

		ACPI_ERROR((AE_INFO, "Type %u is invalid", type));
		return_ACPI_STATUS(AE_TYPE);
	}

	return_ACPI_STATUS(AE_OK);
}