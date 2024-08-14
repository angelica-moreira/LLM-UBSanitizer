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
struct sensor_device_attribute {unsigned int index; } ;
struct regmap {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  LTC2945_FAULT ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct regmap* dev_get_drvdata (struct device*) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t ltc2945_bool_show(struct device *dev,
				 struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct regmap *regmap = dev_get_drvdata(dev);
	unsigned int fault;
	int ret;

	ret = regmap_read(regmap, LTC2945_FAULT, &fault);
	if (ret < 0)
		return ret;

	fault &= attr->index;
	if (fault)		/* Clear reported faults in chip register */
		regmap_update_bits(regmap, LTC2945_FAULT, attr->index, 0);

	return snprintf(buf, PAGE_SIZE, "%d\n", !!fault);
}