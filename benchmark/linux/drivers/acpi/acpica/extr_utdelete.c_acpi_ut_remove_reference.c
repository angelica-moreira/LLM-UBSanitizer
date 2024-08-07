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
struct TYPE_2__ {int /*<<< orphan*/  reference_count; } ;
union acpi_operand_object {TYPE_1__ common; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_ALLOCATIONS ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT_RAW (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ACPI_GET_FUNCTION_NAME ; 
 int /*<<< orphan*/  REF_DECREMENT ; 
 int /*<<< orphan*/  acpi_ut_update_object_reference (union acpi_operand_object*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ut_valid_internal_object (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ut_remove_reference ; 

void acpi_ut_remove_reference(union acpi_operand_object *object)
{

	ACPI_FUNCTION_NAME(ut_remove_reference);

	/*
	 * Allow a NULL pointer to be passed in, just ignore it. This saves
	 * each caller from having to check. Also, ignore NS nodes.
	 */
	if (!object ||
	    (ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED)) {
		return;
	}

	/* Ensure that we have a valid object */

	if (!acpi_ut_valid_internal_object(object)) {
		return;
	}

	ACPI_DEBUG_PRINT_RAW((ACPI_DB_ALLOCATIONS,
			      "%s: Obj %p Current Refs=%X [To Be Decremented]\n",
			      ACPI_GET_FUNCTION_NAME, object,
			      object->common.reference_count));

	/*
	 * Decrement the reference count, and only actually delete the object
	 * if the reference count becomes 0. (Must also decrement the ref count
	 * of all subobjects!)
	 */
	(void)acpi_ut_update_object_reference(object, REF_DECREMENT);
	return;
}