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
struct attribute {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kobject_del (struct kobject*) ; 
 int /*<<< orphan*/  kobject_put (struct kobject*) ; 
 int /*<<< orphan*/  sysfs_remove_file (struct kobject*,struct attribute*) ; 

__attribute__((used)) static void kfd_remove_sysfs_file(struct kobject *kobj, struct attribute *attr)
{
	sysfs_remove_file(kobj, attr);
	kobject_del(kobj);
	kobject_put(kobj);
}