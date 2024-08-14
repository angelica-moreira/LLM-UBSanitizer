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
struct sensor_device_attribute {size_t index; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7470_data {long* pwm_automatic; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
typedef  long ssize_t ;

/* Variables and functions */
 int ADT7470_REG_PWM_AUTO_TEMP (size_t) ; 
 long EINVAL ; 
 long cvt_auto_temp (long) ; 
 struct adt7470_data* dev_get_drvdata (struct device*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 scalar_t__ kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t pwm_auto_temp_store(struct device *dev,
				   struct device_attribute *devattr,
				   const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct adt7470_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int pwm_auto_reg = ADT7470_REG_PWM_AUTO_TEMP(attr->index);
	long temp;
	u8 reg;

	if (kstrtol(buf, 10, &temp))
		return -EINVAL;

	temp = cvt_auto_temp(temp);
	if (temp < 0)
		return temp;

	mutex_lock(&data->lock);
	data->pwm_automatic[attr->index] = temp;
	reg = i2c_smbus_read_byte_data(client, pwm_auto_reg);

	if (!(attr->index % 2)) {
		reg &= 0xF;
		reg |= (temp << 4) & 0xF0;
	} else {
		reg &= 0xF0;
		reg |= temp & 0xF;
	}

	i2c_smbus_write_byte_data(client, pwm_auto_reg, reg);
	mutex_unlock(&data->lock);

	return count;
}