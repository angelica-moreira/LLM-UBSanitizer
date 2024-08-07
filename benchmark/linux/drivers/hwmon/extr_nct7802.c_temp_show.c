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
struct sensor_device_attribute_2 {int /*<<< orphan*/  index; int /*<<< orphan*/  nr; } ;
struct nct7802_data {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 struct nct7802_data* dev_get_drvdata (struct device*) ; 
 int nct7802_read_temp (struct nct7802_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int sprintf (char*,char*,int) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static ssize_t temp_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct nct7802_data *data = dev_get_drvdata(dev);
	struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
	int err, temp;

	err = nct7802_read_temp(data, sattr->nr, sattr->index, &temp);
	if (err < 0)
		return err;

	return sprintf(buf, "%d\n", temp);
}