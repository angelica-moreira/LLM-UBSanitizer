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
struct host1x_device {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __host1x_device_del (struct host1x_device*) ; 
 int /*<<< orphan*/  kfree (struct host1x_device*) ; 
 struct host1x_device* to_host1x_device (struct device*) ; 

__attribute__((used)) static void host1x_device_release(struct device *dev)
{
	struct host1x_device *device = to_host1x_device(dev);

	__host1x_device_del(device);
	kfree(device);
}