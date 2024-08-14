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
struct emc2103_data {int fan_target; int fan_multiplier; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int FAN_RPM_FACTOR ; 
 struct emc2103_data* emc2103_update_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t
fan1_target_show(struct device *dev, struct device_attribute *da, char *buf)
{
	struct emc2103_data *data = emc2103_update_device(dev);
	int rpm = 0;

	/* high byte of 0xff indicates disabled so return 0 */
	if ((data->fan_target != 0) && ((data->fan_target & 0x1fe0) != 0x1fe0))
		rpm = (FAN_RPM_FACTOR * data->fan_multiplier)
			/ data->fan_target;

	return sprintf(buf, "%d\n", rpm);
}