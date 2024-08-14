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
struct device {int dummy; } ;

/* Variables and functions */
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,unsigned char,int,void*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static int adxl34x_smbus_read_block(struct device *dev,
				    unsigned char reg, int count,
				    void *buf)
{
	struct i2c_client *client = to_i2c_client(dev);

	return i2c_smbus_read_i2c_block_data(client, reg, count, buf);
}