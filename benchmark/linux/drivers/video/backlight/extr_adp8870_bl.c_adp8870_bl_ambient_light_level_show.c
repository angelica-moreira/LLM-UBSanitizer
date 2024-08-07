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
typedef  int uint8_t ;
typedef  int uint16_t ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adp8870_bl {int /*<<< orphan*/  lock; int /*<<< orphan*/  client; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ADP8870_PH1LEVH ; 
 int /*<<< orphan*/  ADP8870_PH1LEVL ; 
 int adp8870_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 struct adp8870_bl* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t adp8870_bl_ambient_light_level_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct adp8870_bl *data = dev_get_drvdata(dev);
	int error;
	uint8_t reg_val;
	uint16_t ret_val;

	mutex_lock(&data->lock);
	error = adp8870_read(data->client, ADP8870_PH1LEVL, &reg_val);
	if (error < 0) {
		mutex_unlock(&data->lock);
		return error;
	}
	ret_val = reg_val;
	error = adp8870_read(data->client, ADP8870_PH1LEVH, &reg_val);
	mutex_unlock(&data->lock);

	if (error < 0)
		return error;

	/* Return 13-bit conversion value for the first light sensor */
	ret_val += (reg_val & 0x1F) << 8;

	return sprintf(buf, "%u\n", ret_val);
}