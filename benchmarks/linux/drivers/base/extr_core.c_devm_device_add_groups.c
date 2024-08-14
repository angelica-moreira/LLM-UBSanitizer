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
union device_attr_group_devres {struct attribute_group const** groups; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct attribute_group {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  devm_attr_groups_remove ; 
 int /*<<< orphan*/  devres_add (struct device*,union device_attr_group_devres*) ; 
 union device_attr_group_devres* devres_alloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devres_free (union device_attr_group_devres*) ; 
 int sysfs_create_groups (int /*<<< orphan*/ *,struct attribute_group const**) ; 

int devm_device_add_groups(struct device *dev,
			   const struct attribute_group **groups)
{
	union device_attr_group_devres *devres;
	int error;

	devres = devres_alloc(devm_attr_groups_remove,
			      sizeof(*devres), GFP_KERNEL);
	if (!devres)
		return -ENOMEM;

	error = sysfs_create_groups(&dev->kobj, groups);
	if (error) {
		devres_free(devres);
		return error;
	}

	devres->groups = groups;
	devres_add(dev, devres);
	return 0;
}