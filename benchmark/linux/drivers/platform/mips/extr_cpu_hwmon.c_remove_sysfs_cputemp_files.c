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
struct kobject {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/ * hwmon_cputemp ; 
 int nr_packages ; 
 int /*<<< orphan*/  sysfs_remove_files (struct kobject*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void remove_sysfs_cputemp_files(struct kobject *kobj)
{
	int i;

	for (i=0; i<nr_packages; i++)
		sysfs_remove_files(kobj, hwmon_cputemp[i]);
}