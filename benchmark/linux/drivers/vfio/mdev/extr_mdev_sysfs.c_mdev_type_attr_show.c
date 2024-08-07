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
struct mdev_type_attribute {int /*<<< orphan*/  (* show ) (struct kobject*,int /*<<< orphan*/ ,char*) ;} ;
struct mdev_type {TYPE_1__* parent; } ;
struct kobject {int dummy; } ;
struct attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  stub1 (struct kobject*,int /*<<< orphan*/ ,char*) ; 
 struct mdev_type* to_mdev_type (struct kobject*) ; 
 struct mdev_type_attribute* to_mdev_type_attr (struct attribute*) ; 

__attribute__((used)) static ssize_t mdev_type_attr_show(struct kobject *kobj,
				     struct attribute *__attr, char *buf)
{
	struct mdev_type_attribute *attr = to_mdev_type_attr(__attr);
	struct mdev_type *type = to_mdev_type(kobj);
	ssize_t ret = -EIO;

	if (attr->show)
		ret = attr->show(kobj, type->parent->dev, buf);
	return ret;
}