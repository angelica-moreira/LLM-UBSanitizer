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
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct amc6821_data {int /*<<< orphan*/  update_lock; struct i2c_client* client; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int AMC6821_CONF1_FDRC0 ; 
 int AMC6821_CONF1_FDRC1 ; 
 int /*<<< orphan*/  AMC6821_REG_CONF1 ; 
 size_t EINVAL ; 
 size_t EIO ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct amc6821_data* dev_get_drvdata (struct device*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 scalar_t__ i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t pwm1_enable_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct amc6821_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int config = kstrtol(buf, 10, &val);
	if (config)
		return config;

	mutex_lock(&data->update_lock);
	config = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF1);
	if (config < 0) {
			dev_err(&client->dev,
			"Error reading configuration register, aborting.\n");
			count = config;
			goto unlock;
	}

	switch (val) {
	case 1:
		config &= ~AMC6821_CONF1_FDRC0;
		config &= ~AMC6821_CONF1_FDRC1;
		break;
	case 2:
		config &= ~AMC6821_CONF1_FDRC0;
		config |= AMC6821_CONF1_FDRC1;
		break;
	case 3:
		config |= AMC6821_CONF1_FDRC0;
		config |= AMC6821_CONF1_FDRC1;
		break;
	default:
		count = -EINVAL;
		goto unlock;
	}
	if (i2c_smbus_write_byte_data(client, AMC6821_REG_CONF1, config)) {
			dev_err(&client->dev,
			"Configuration register write error, aborting.\n");
			count = -EIO;
	}
unlock:
	mutex_unlock(&data->update_lock);
	return count;
}