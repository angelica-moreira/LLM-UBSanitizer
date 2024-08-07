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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct dasd_device {TYPE_1__* discipline; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  __u8 ;
struct TYPE_2__ {int /*<<< orphan*/  (* reset_path ) (struct dasd_device*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 size_t ENODEV ; 
 scalar_t__ IS_ERR (struct dasd_device*) ; 
 struct dasd_device* dasd_device_from_cdev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dasd_put_device (struct dasd_device*) ; 
 scalar_t__ kstrtouint (char const*,int,unsigned int*) ; 
 int /*<<< orphan*/  stub1 (struct dasd_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_ccwdev (struct device*) ; 

__attribute__((used)) static ssize_t
dasd_path_reset_store(struct device *dev, struct device_attribute *attr,
		      const char *buf, size_t count)
{
	struct dasd_device *device;
	unsigned int val;

	device = dasd_device_from_cdev(to_ccwdev(dev));
	if (IS_ERR(device))
		return -ENODEV;

	if ((kstrtouint(buf, 16, &val) != 0) || val > 0xff)
		val = 0;

	if (device->discipline && device->discipline->reset_path)
		device->discipline->reset_path(device, (__u8) val);

	dasd_put_device(device);
	return count;
}