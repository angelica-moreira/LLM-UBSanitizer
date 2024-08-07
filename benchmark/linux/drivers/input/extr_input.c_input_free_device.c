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
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct input_dev {TYPE_1__ dev; scalar_t__ devres_managed; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_input_device_match ; 
 int /*<<< orphan*/  devm_input_device_release ; 
 int /*<<< orphan*/  devres_destroy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct input_dev*) ; 
 int /*<<< orphan*/  input_put_device (struct input_dev*) ; 

void input_free_device(struct input_dev *dev)
{
	if (dev) {
		if (dev->devres_managed)
			WARN_ON(devres_destroy(dev->dev.parent,
						devm_input_device_release,
						devm_input_device_match,
						dev));
		input_put_device(dev);
	}
}