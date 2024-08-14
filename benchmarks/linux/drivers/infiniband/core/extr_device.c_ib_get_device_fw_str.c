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
struct TYPE_2__ {int /*<<< orphan*/  (* get_dev_fw_str ) (struct ib_device*,char*) ;} ;
struct ib_device {TYPE_1__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct ib_device*,char*) ; 

void ib_get_device_fw_str(struct ib_device *dev, char *str)
{
	if (dev->ops.get_dev_fw_str)
		dev->ops.get_dev_fw_str(dev, str);
	else
		str[0] = '\0';
}