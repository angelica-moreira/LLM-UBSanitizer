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
struct acpi_buffer {scalar_t__ length; int /*<<< orphan*/  pointer; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  scalar_t__ acpi_size ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_INFO ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  acpi_format_exception (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_rs_convert_resources_to_aml (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_rs_get_aml_length (int /*<<< orphan*/ ,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  acpi_ut_initialize_buffer (struct acpi_buffer*,scalar_t__) ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rs_create_aml_resources ; 

acpi_status
acpi_rs_create_aml_resources(struct acpi_buffer *resource_list,
			     struct acpi_buffer *output_buffer)
{
	acpi_status status;
	acpi_size aml_size_needed = 0;

	ACPI_FUNCTION_TRACE(rs_create_aml_resources);

	/* Params already validated, no need to re-validate here */

	ACPI_DEBUG_PRINT((ACPI_DB_INFO, "ResourceList Buffer = %p\n",
			  resource_list->pointer));

	/* Get the buffer size needed for the AML byte stream */

	status =
	    acpi_rs_get_aml_length(resource_list->pointer,
				   resource_list->length, &aml_size_needed);

	ACPI_DEBUG_PRINT((ACPI_DB_INFO, "AmlSizeNeeded=%X, %s\n",
			  (u32)aml_size_needed, acpi_format_exception(status)));
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/* Validate/Allocate/Clear caller buffer */

	status = acpi_ut_initialize_buffer(output_buffer, aml_size_needed);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/* Do the conversion */

	status = acpi_rs_convert_resources_to_aml(resource_list->pointer,
						  aml_size_needed,
						  output_buffer->pointer);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	ACPI_DEBUG_PRINT((ACPI_DB_INFO, "OutputBuffer %p Length %X\n",
			  output_buffer->pointer, (u32) output_buffer->length));
	return_ACPI_STATUS(AE_OK);
}