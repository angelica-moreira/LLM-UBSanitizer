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
typedef  int u8 ;
struct sensor_device_attribute_2 {size_t nr; int index; } ;
struct pem_data {int* data_string; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct pem_data*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PTR_ERR (struct pem_data*) ; 
 struct pem_data* pem_update_device (struct device*) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static ssize_t pem_bool_show(struct device *dev, struct device_attribute *da,
			     char *buf)
{
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);
	struct pem_data *data = pem_update_device(dev);
	u8 status;

	if (IS_ERR(data))
		return PTR_ERR(data);

	status = data->data_string[attr->nr] & attr->index;
	return snprintf(buf, PAGE_SIZE, "%d\n", !!status);
}