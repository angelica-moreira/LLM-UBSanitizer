#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct device {int /*<<< orphan*/  kobj; TYPE_3__* class; scalar_t__ parent; } ;
struct TYPE_6__ {TYPE_2__* p; } ;
struct TYPE_4__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_5__ {TYPE_1__ subsys; } ;

/* Variables and functions */
 TYPE_3__ block_class ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 scalar_t__ dev_of_node (struct device*) ; 
 scalar_t__ device_is_not_partition (struct device*) ; 
 int /*<<< orphan*/  sysfs_delete_link (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ sysfs_deprecated ; 
 int /*<<< orphan*/  sysfs_remove_link (int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static void device_remove_class_symlinks(struct device *dev)
{
	if (dev_of_node(dev))
		sysfs_remove_link(&dev->kobj, "of_node");

	if (!dev->class)
		return;

	if (dev->parent && device_is_not_partition(dev))
		sysfs_remove_link(&dev->kobj, "device");
	sysfs_remove_link(&dev->kobj, "subsystem");
#ifdef CONFIG_BLOCK
	if (sysfs_deprecated && dev->class == &block_class)
		return;
#endif
	sysfs_delete_link(&dev->class->p->subsys.kobj, &dev->kobj, dev_name(dev));
}