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
struct fschmd_data {size_t kind; unsigned long* fan_min; int /*<<< orphan*/  update_lock; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int /*<<< orphan*/ ** FSCHMD_REG_FAN_MIN ; 
 unsigned long clamp_val (unsigned long,int,int) ; 
 struct fschmd_data* dev_get_drvdata (struct device*) ; 
 size_t fscsyl ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  to_i2c_client (struct device*) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t pwm_auto_point1_pwm_store(struct device *dev,
					 struct device_attribute *devattr,
					 const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct fschmd_data *data = dev_get_drvdata(dev);
	unsigned long v;
	int err;

	err = kstrtoul(buf, 10, &v);
	if (err)
		return err;

	/* reg: 0 = allow turning off (except on the syl), 1-255 = 50-100% */
	if (v || data->kind == fscsyl) {
		v = clamp_val(v, 128, 255);
		v = (v - 128) * 2 + 1;
	}

	mutex_lock(&data->update_lock);

	i2c_smbus_write_byte_data(to_i2c_client(dev),
		FSCHMD_REG_FAN_MIN[data->kind][index], v);
	data->fan_min[index] = v;

	mutex_unlock(&data->update_lock);

	return count;
}