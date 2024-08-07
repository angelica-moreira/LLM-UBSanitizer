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
struct device {int /*<<< orphan*/  kobj; } ;

/* Variables and functions */
 int /*<<< orphan*/  err_inject_attr_group ; 
 struct device* get_cpu_device (unsigned int) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int err_inject_remove_dev(unsigned int cpu)
{
	struct device *sys_dev = get_cpu_device(cpu);

	sysfs_remove_group(&sys_dev->kobj, &err_inject_attr_group);
	return 0;
}