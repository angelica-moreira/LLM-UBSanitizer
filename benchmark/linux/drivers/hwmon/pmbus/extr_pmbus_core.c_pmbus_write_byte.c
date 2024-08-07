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
typedef  int /*<<< orphan*/  u8 ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int pmbus_set_page (struct i2c_client*,int) ; 

int pmbus_write_byte(struct i2c_client *client, int page, u8 value)
{
	int rv;

	rv = pmbus_set_page(client, page);
	if (rv < 0)
		return rv;

	return i2c_smbus_write_byte(client, value);
}