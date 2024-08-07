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
struct proc_dir_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_AC_CLASS ; 
 int /*<<< orphan*/ * acpi_ac_dir ; 
 int /*<<< orphan*/  acpi_root_dir ; 
 int /*<<< orphan*/  cm_sbs_mutex ; 
 scalar_t__ lock_ac_dir_cnt ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  remove_proc_entry (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void acpi_unlock_ac_dir(struct proc_dir_entry *acpi_ac_dir_param)
{
	mutex_lock(&cm_sbs_mutex);
	if (acpi_ac_dir_param)
		lock_ac_dir_cnt--;
	if (lock_ac_dir_cnt == 0 && acpi_ac_dir_param && acpi_ac_dir) {
		remove_proc_entry(ACPI_AC_CLASS, acpi_root_dir);
		acpi_ac_dir = NULL;
	}
	mutex_unlock(&cm_sbs_mutex);
}