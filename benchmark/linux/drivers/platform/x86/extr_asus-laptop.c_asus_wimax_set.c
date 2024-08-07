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
struct asus_laptop {int /*<<< orphan*/  handle; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  METHOD_WIMAX ; 
 int /*<<< orphan*/  pr_warn (char*,int) ; 
 scalar_t__ write_acpi_int (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int asus_wimax_set(struct asus_laptop *asus, int status)
{
	if (write_acpi_int(asus->handle, METHOD_WIMAX, !!status)) {
		pr_warn("Error setting wimax status to %d\n", status);
		return -EIO;
	}
	return 0;
}