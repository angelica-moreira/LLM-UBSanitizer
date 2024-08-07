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
struct pc87360_data {int* temp_status; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {unsigned int index; } ;

/* Variables and functions */
 int CHAN_ALM_MAX ; 
 struct pc87360_data* pc87360_update_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t temp_max_alarm_show(struct device *dev,
				   struct device_attribute *devattr,
				   char *buf)
{
	struct pc87360_data *data = pc87360_update_device(dev);
	unsigned nr = to_sensor_dev_attr(devattr)->index;

	return sprintf(buf, "%u\n", !!(data->temp_status[nr] & CHAN_ALM_MAX));
}