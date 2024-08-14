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
struct TYPE_2__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  out_crc; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_AML_OUT_KERN ; 
 int /*<<< orphan*/  __acpi_aml_access_ok (int /*<<< orphan*/ ) ; 
 scalar_t__ __acpi_aml_writable (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_1__ acpi_aml_io ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool acpi_aml_kern_writable(void)
{
	bool ret;

	mutex_lock(&acpi_aml_io.lock);
	ret = !__acpi_aml_access_ok(ACPI_AML_OUT_KERN) ||
	      __acpi_aml_writable(&acpi_aml_io.out_crc, ACPI_AML_OUT_KERN);
	mutex_unlock(&acpi_aml_io.lock);
	return ret;
}