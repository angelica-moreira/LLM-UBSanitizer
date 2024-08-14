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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct amc6821_data {int pwm1; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct amc6821_data* amc6821_update_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t pwm1_show(struct device *dev, struct device_attribute *devattr,
			 char *buf)
{
	struct amc6821_data *data = amc6821_update_device(dev);
	return sprintf(buf, "%d\n", data->pwm1);
}