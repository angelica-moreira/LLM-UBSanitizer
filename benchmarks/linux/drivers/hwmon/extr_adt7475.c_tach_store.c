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
struct sensor_device_attribute_2 {size_t index; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7475_data {int /*<<< orphan*/  lock; int /*<<< orphan*/ ** tach; struct i2c_client* client; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 size_t MIN ; 
 int /*<<< orphan*/  TACH_MIN_REG (size_t) ; 
 int /*<<< orphan*/  adt7475_write_word (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct adt7475_data* dev_get_drvdata (struct device*) ; 
 scalar_t__ kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rpm2tach (unsigned long) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static ssize_t tach_store(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{

	struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
	struct adt7475_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	mutex_lock(&data->lock);

	data->tach[MIN][sattr->index] = rpm2tach(val);

	adt7475_write_word(client, TACH_MIN_REG(sattr->index),
			   data->tach[MIN][sattr->index]);

	mutex_unlock(&data->lock);
	return count;
}