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
struct w83792d_data {int** sf2_levels; } ;
struct sensor_device_attribute_2 {int nr; int index; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 struct w83792d_data* w83792d_update_device (struct device*) ; 

__attribute__((used)) static ssize_t
show_sf2_level(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute_2 *sensor_attr
	  = to_sensor_dev_attr_2(attr);
	int nr = sensor_attr->nr;
	int index = sensor_attr->index;
	struct w83792d_data *data = w83792d_update_device(dev);
	return sprintf(buf, "%d\n",
			(((data->sf2_levels[index-1][nr]) * 100) / 15));
}