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
struct kvm_io_device {int dummy; } ;
struct kvm_io_bus {int dev_count; TYPE_1__* range; } ;
struct TYPE_2__ {struct kvm_io_device* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct kvm_io_bus*) ; 
 int /*<<< orphan*/  kvm_iodevice_destructor (struct kvm_io_device*) ; 

__attribute__((used)) static void kvm_io_bus_destroy(struct kvm_io_bus *bus)
{
	int i;

	for (i = 0; i < bus->dev_count; i++) {
		struct kvm_io_device *pos = bus->range[i].dev;

		kvm_iodevice_destructor(pos);
	}
	kfree(bus);
}