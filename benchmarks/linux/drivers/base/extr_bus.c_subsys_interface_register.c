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
struct subsys_interface {int /*<<< orphan*/  (* add_dev ) (struct device*,struct subsys_interface*) ;int /*<<< orphan*/  node; int /*<<< orphan*/  subsys; } ;
struct subsys_dev_iter {int dummy; } ;
struct device {int dummy; } ;
struct bus_type {TYPE_1__* p; } ;
struct TYPE_2__ {int /*<<< orphan*/  mutex; int /*<<< orphan*/  interfaces; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 struct bus_type* bus_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct device*,struct subsys_interface*) ; 
 int /*<<< orphan*/  subsys_dev_iter_exit (struct subsys_dev_iter*) ; 
 int /*<<< orphan*/  subsys_dev_iter_init (struct subsys_dev_iter*,struct bus_type*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct device* subsys_dev_iter_next (struct subsys_dev_iter*) ; 

int subsys_interface_register(struct subsys_interface *sif)
{
	struct bus_type *subsys;
	struct subsys_dev_iter iter;
	struct device *dev;

	if (!sif || !sif->subsys)
		return -ENODEV;

	subsys = bus_get(sif->subsys);
	if (!subsys)
		return -EINVAL;

	mutex_lock(&subsys->p->mutex);
	list_add_tail(&sif->node, &subsys->p->interfaces);
	if (sif->add_dev) {
		subsys_dev_iter_init(&iter, subsys, NULL, NULL);
		while ((dev = subsys_dev_iter_next(&iter)))
			sif->add_dev(dev, sif);
		subsys_dev_iter_exit(&iter);
	}
	mutex_unlock(&subsys->p->mutex);

	return 0;
}