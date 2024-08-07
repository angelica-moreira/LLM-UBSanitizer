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
struct TYPE_2__ {int /*<<< orphan*/  probe_type; struct module* owner; int /*<<< orphan*/ * bus; } ;
struct serdev_device_driver {TYPE_1__ driver; } ;
struct module {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PROBE_PREFER_ASYNCHRONOUS ; 
 int driver_register (TYPE_1__*) ; 
 int /*<<< orphan*/  serdev_bus_type ; 

int __serdev_device_driver_register(struct serdev_device_driver *sdrv, struct module *owner)
{
	sdrv->driver.bus = &serdev_bus_type;
	sdrv->driver.owner = owner;

	/* force drivers to async probe so I/O is possible in probe */
        sdrv->driver.probe_type = PROBE_PREFER_ASYNCHRONOUS;

	return driver_register(&sdrv->driver);
}