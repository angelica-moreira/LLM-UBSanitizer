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
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adm1026_data {int /*<<< orphan*/  update_lock; int /*<<< orphan*/ * in_min; struct i2c_client* client; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/ * ADM1026_REG_IN_MIN ; 
 int /*<<< orphan*/  INS_TO_REG (int,scalar_t__) ; 
 scalar_t__ INT_MAX ; 
 int /*<<< orphan*/  INT_MIN ; 
 scalar_t__ NEG12_OFFSET ; 
 int /*<<< orphan*/  adm1026_write_value (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ clamp_val (long,int /*<<< orphan*/ ,scalar_t__) ; 
 struct adm1026_data* dev_get_drvdata (struct device*) ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t in16_min_store(struct device *dev,
			      struct device_attribute *attr, const char *buf,
			      size_t count)
{
	struct adm1026_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_min[16] = INS_TO_REG(16,
				      clamp_val(val, INT_MIN,
						INT_MAX - NEG12_OFFSET) +
				      NEG12_OFFSET);
	adm1026_write_value(client, ADM1026_REG_IN_MIN[16], data->in_min[16]);
	mutex_unlock(&data->update_lock);
	return count;
}