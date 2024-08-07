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
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/ * ktype; int /*<<< orphan*/  kset; } ;
struct TYPE_5__ {TYPE_3__ kobj; } ;
struct subsys_private {int drivers_autoprobe; TYPE_1__ subsys; TYPE_1__* devices_kset; TYPE_1__* drivers_kset; int /*<<< orphan*/  klist_drivers; int /*<<< orphan*/  klist_devices; int /*<<< orphan*/  mutex; int /*<<< orphan*/  interfaces; int /*<<< orphan*/  bus_notifier; struct bus_type* bus; } ;
struct lock_class_key {int dummy; } ;
struct bus_type {struct subsys_private* p; int /*<<< orphan*/  name; int /*<<< orphan*/  bus_groups; struct lock_class_key lock_key; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLOCKING_INIT_NOTIFIER_HEAD (int /*<<< orphan*/ *) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __mutex_init (int /*<<< orphan*/ *,char*,struct lock_class_key*) ; 
 int add_probe_files (struct bus_type*) ; 
 int bus_add_groups (struct bus_type*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_attr_uevent ; 
 int bus_create_file (struct bus_type*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_kset ; 
 int /*<<< orphan*/  bus_ktype ; 
 int /*<<< orphan*/  bus_remove_file (struct bus_type*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct subsys_private*) ; 
 int /*<<< orphan*/ * klist_devices_get ; 
 int /*<<< orphan*/ * klist_devices_put ; 
 int /*<<< orphan*/  klist_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int kobject_set_name (TYPE_3__*,char*,int /*<<< orphan*/ ) ; 
 void* kset_create_and_add (char*,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int kset_register (TYPE_1__*) ; 
 int /*<<< orphan*/  kset_unregister (TYPE_1__*) ; 
 struct subsys_private* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  remove_probe_files (struct bus_type*) ; 

int bus_register(struct bus_type *bus)
{
	int retval;
	struct subsys_private *priv;
	struct lock_class_key *key = &bus->lock_key;

	priv = kzalloc(sizeof(struct subsys_private), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->bus = bus;
	bus->p = priv;

	BLOCKING_INIT_NOTIFIER_HEAD(&priv->bus_notifier);

	retval = kobject_set_name(&priv->subsys.kobj, "%s", bus->name);
	if (retval)
		goto out;

	priv->subsys.kobj.kset = bus_kset;
	priv->subsys.kobj.ktype = &bus_ktype;
	priv->drivers_autoprobe = 1;

	retval = kset_register(&priv->subsys);
	if (retval)
		goto out;

	retval = bus_create_file(bus, &bus_attr_uevent);
	if (retval)
		goto bus_uevent_fail;

	priv->devices_kset = kset_create_and_add("devices", NULL,
						 &priv->subsys.kobj);
	if (!priv->devices_kset) {
		retval = -ENOMEM;
		goto bus_devices_fail;
	}

	priv->drivers_kset = kset_create_and_add("drivers", NULL,
						 &priv->subsys.kobj);
	if (!priv->drivers_kset) {
		retval = -ENOMEM;
		goto bus_drivers_fail;
	}

	INIT_LIST_HEAD(&priv->interfaces);
	__mutex_init(&priv->mutex, "subsys mutex", key);
	klist_init(&priv->klist_devices, klist_devices_get, klist_devices_put);
	klist_init(&priv->klist_drivers, NULL, NULL);

	retval = add_probe_files(bus);
	if (retval)
		goto bus_probe_files_fail;

	retval = bus_add_groups(bus, bus->bus_groups);
	if (retval)
		goto bus_groups_fail;

	pr_debug("bus: '%s': registered\n", bus->name);
	return 0;

bus_groups_fail:
	remove_probe_files(bus);
bus_probe_files_fail:
	kset_unregister(bus->p->drivers_kset);
bus_drivers_fail:
	kset_unregister(bus->p->devices_kset);
bus_devices_fail:
	bus_remove_file(bus, &bus_attr_uevent);
bus_uevent_fail:
	kset_unregister(&bus->p->subsys);
out:
	kfree(bus->p);
	bus->p = NULL;
	return retval;
}