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
struct tc654_data {int /*<<< orphan*/  update_lock; int /*<<< orphan*/  duty_cycle; int /*<<< orphan*/  config; struct i2c_client* client; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int /*<<< orphan*/  TC654_REG_CONFIG ; 
 int /*<<< orphan*/  TC654_REG_CONFIG_SDM ; 
 int /*<<< orphan*/  TC654_REG_DUTY_CYCLE ; 
 struct tc654_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  find_closest (unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tc654_pwm_map ; 

__attribute__((used)) static ssize_t pwm_store(struct device *dev, struct device_attribute *da,
			 const char *buf, size_t count)
{
	struct tc654_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int ret;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;
	if (val > 255)
		return -EINVAL;

	mutex_lock(&data->update_lock);

	if (val == 0)
		data->config |= TC654_REG_CONFIG_SDM;
	else
		data->config &= ~TC654_REG_CONFIG_SDM;

	data->duty_cycle = find_closest(val, tc654_pwm_map,
					ARRAY_SIZE(tc654_pwm_map));

	ret = i2c_smbus_write_byte_data(client, TC654_REG_CONFIG, data->config);
	if (ret < 0)
		goto out;

	ret = i2c_smbus_write_byte_data(client, TC654_REG_DUTY_CYCLE,
					data->duty_cycle);

out:
	mutex_unlock(&data->update_lock);
	return ret < 0 ? ret : count;
}