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
struct module {int dummy; } ;
struct TYPE_2__ {char const* mod_name; int /*<<< orphan*/ * bus; struct module* owner; } ;
struct mcb_driver {TYPE_1__ driver; int /*<<< orphan*/  remove; int /*<<< orphan*/  probe; } ;

/* Variables and functions */
 int EINVAL ; 
 int driver_register (TYPE_1__*) ; 
 int /*<<< orphan*/  mcb_bus_type ; 

int __mcb_register_driver(struct mcb_driver *drv, struct module *owner,
			const char *mod_name)
{
	if (!drv->probe || !drv->remove)
		return -EINVAL;

	drv->driver.owner = owner;
	drv->driver.bus = &mcb_bus_type;
	drv->driver.mod_name = mod_name;

	return driver_register(&drv->driver);
}