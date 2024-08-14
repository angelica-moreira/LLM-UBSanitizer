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
struct acpi_rw_lock {int num_readers; int /*<<< orphan*/  reader_mutex; int /*<<< orphan*/  writer_mutex; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_WAIT_FOREVER ; 
 int /*<<< orphan*/  acpi_os_acquire_mutex (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_os_release_mutex (int /*<<< orphan*/ ) ; 

acpi_status acpi_ut_acquire_read_lock(struct acpi_rw_lock *lock)
{
	acpi_status status;

	status = acpi_os_acquire_mutex(lock->reader_mutex, ACPI_WAIT_FOREVER);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	/* Acquire the write lock only for the first reader */

	lock->num_readers++;
	if (lock->num_readers == 1) {
		status =
		    acpi_os_acquire_mutex(lock->writer_mutex,
					  ACPI_WAIT_FOREVER);
	}

	acpi_os_release_mutex(lock->reader_mutex);
	return (status);
}