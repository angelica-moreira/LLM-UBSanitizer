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
struct TYPE_2__ {int /*<<< orphan*/ * bus; } ;
struct anybuss_client_driver {TYPE_1__ driver; } ;

/* Variables and functions */
 int /*<<< orphan*/  anybus_bus ; 
 int driver_register (TYPE_1__*) ; 

int anybuss_client_driver_register(struct anybuss_client_driver *drv)
{
	drv->driver.bus = &anybus_bus;
	return driver_register(&drv->driver);
}