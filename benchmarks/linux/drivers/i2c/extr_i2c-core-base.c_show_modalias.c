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
struct i2c_client {int /*<<< orphan*/  name; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ENODEV ; 
 char* I2C_MODULE_PREFIX ; 
 scalar_t__ PAGE_SIZE ; 
 int acpi_device_modalias (struct device*,char*,scalar_t__) ; 
 int of_device_modalias (struct device*,char*,scalar_t__) ; 
 int sprintf (char*,char*,char*,int /*<<< orphan*/ ) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static ssize_t
show_modalias(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	int len;

	len = of_device_modalias(dev, buf, PAGE_SIZE);
	if (len != -ENODEV)
		return len;

	len = acpi_device_modalias(dev, buf, PAGE_SIZE -1);
	if (len != -ENODEV)
		return len;

	return sprintf(buf, "%s%s\n", I2C_MODULE_PREFIX, client->name);
}