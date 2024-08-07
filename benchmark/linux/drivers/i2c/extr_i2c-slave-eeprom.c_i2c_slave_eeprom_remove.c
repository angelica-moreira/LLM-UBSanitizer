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
struct TYPE_2__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {TYPE_1__ dev; } ;
struct eeprom_data {int /*<<< orphan*/  bin; } ;

/* Variables and functions */
 struct eeprom_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_slave_unregister (struct i2c_client*) ; 
 int /*<<< orphan*/  sysfs_remove_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int i2c_slave_eeprom_remove(struct i2c_client *client)
{
	struct eeprom_data *eeprom = i2c_get_clientdata(client);

	i2c_slave_unregister(client);
	sysfs_remove_bin_file(&client->dev.kobj, &eeprom->bin);

	return 0;
}