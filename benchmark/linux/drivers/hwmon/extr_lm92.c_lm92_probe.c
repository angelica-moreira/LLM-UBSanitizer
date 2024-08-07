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
struct lm92_data {int /*<<< orphan*/  update_lock; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct lm92_data*,int /*<<< orphan*/ ) ; 
 struct lm92_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lm92_groups ; 
 int /*<<< orphan*/  lm92_init_client (struct i2c_client*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int lm92_probe(struct i2c_client *new_client,
		      const struct i2c_device_id *id)
{
	struct device *hwmon_dev;
	struct lm92_data *data;

	data = devm_kzalloc(&new_client->dev, sizeof(struct lm92_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = new_client;
	mutex_init(&data->update_lock);

	/* Initialize the chipset */
	lm92_init_client(new_client);

	hwmon_dev = devm_hwmon_device_register_with_groups(&new_client->dev,
							   new_client->name,
							   data, lm92_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}