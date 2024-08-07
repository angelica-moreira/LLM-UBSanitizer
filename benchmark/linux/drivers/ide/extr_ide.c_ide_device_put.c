#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct module {int dummy; } ;
struct device {TYPE_3__* driver; } ;
struct TYPE_9__ {int /*<<< orphan*/  gendev; TYPE_2__* hwif; } ;
typedef  TYPE_4__ ide_drive_t ;
struct TYPE_8__ {struct module* owner; } ;
struct TYPE_7__ {TYPE_1__* host; } ;
struct TYPE_6__ {struct device** dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  module_put (struct module*) ; 
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ *) ; 

void ide_device_put(ide_drive_t *drive)
{
#ifdef CONFIG_MODULE_UNLOAD
	struct device *host_dev = drive->hwif->host->dev[0];
	struct module *module = host_dev ? host_dev->driver->owner : NULL;

	module_put(module);
#endif
	put_device(&drive->gendev);
}