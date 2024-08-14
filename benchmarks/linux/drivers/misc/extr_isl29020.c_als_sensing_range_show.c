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
typedef  int ssize_t ;

/* Variables and functions */
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int sprintf (char*,char*,int) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static ssize_t als_sensing_range_show(struct device *dev,
			struct device_attribute *attr,  char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	int  val;

	val = i2c_smbus_read_byte_data(client, 0x00);

	if (val < 0)
		return val;
	return sprintf(buf, "%d000\n", 1 << (2 * (val & 3)));

}