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
struct device_driver {TYPE_1__* p; } ;
struct attribute_group {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  kobj; } ;

/* Variables and functions */
 int /*<<< orphan*/  sysfs_remove_groups (int /*<<< orphan*/ *,struct attribute_group const**) ; 

void driver_remove_groups(struct device_driver *drv,
			  const struct attribute_group **groups)
{
	sysfs_remove_groups(&drv->p->kobj, groups);
}