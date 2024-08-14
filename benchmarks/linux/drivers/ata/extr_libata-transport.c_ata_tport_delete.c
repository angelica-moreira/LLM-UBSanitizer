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
struct device {int dummy; } ;
struct ata_port {int /*<<< orphan*/  link; struct device tdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ata_tlink_delete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_del (struct device*) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int /*<<< orphan*/  transport_destroy_device (struct device*) ; 
 int /*<<< orphan*/  transport_remove_device (struct device*) ; 

void ata_tport_delete(struct ata_port *ap)
{
	struct device *dev = &ap->tdev;

	ata_tlink_delete(&ap->link);

	transport_remove_device(dev);
	device_del(dev);
	transport_destroy_device(dev);
	put_device(dev);
}