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
struct fw_unit {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fw_device_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fw_parent_device (struct fw_unit*) ; 
 struct fw_unit* fw_unit (struct device*) ; 
 int /*<<< orphan*/  kfree (struct fw_unit*) ; 

__attribute__((used)) static void fw_unit_release(struct device *dev)
{
	struct fw_unit *unit = fw_unit(dev);

	fw_device_put(fw_parent_device(unit));
	kfree(unit);
}