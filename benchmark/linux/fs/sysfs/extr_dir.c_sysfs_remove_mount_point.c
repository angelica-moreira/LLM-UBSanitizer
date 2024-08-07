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
struct kobject {struct kernfs_node* sd; } ;
struct kernfs_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kernfs_remove_by_name_ns (struct kernfs_node*,char const*,int /*<<< orphan*/ *) ; 

void sysfs_remove_mount_point(struct kobject *parent_kobj, const char *name)
{
	struct kernfs_node *parent = parent_kobj->sd;

	kernfs_remove_by_name_ns(parent, name, NULL);
}