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
struct mei_cl_device {TYPE_3__* bus; } ;
struct TYPE_6__ {TYPE_2__* dev; } ;
struct TYPE_5__ {TYPE_1__* driver; } ;
struct TYPE_4__ {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 int try_module_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool mei_cl_bus_module_get(struct mei_cl_device *cldev)
{
	return try_module_get(cldev->bus->dev->driver->owner);
}