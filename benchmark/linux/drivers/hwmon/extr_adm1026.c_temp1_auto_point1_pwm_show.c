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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_2__ {int auto_pwm_min; } ;
struct adm1026_data {TYPE_1__ pwm1; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct adm1026_data* adm1026_update_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t temp1_auto_point1_pwm_show(struct device *dev,
					  struct device_attribute *attr,
					  char *buf)
{
	struct adm1026_data *data = adm1026_update_device(dev);
	return sprintf(buf, "%d\n", data->pwm1.auto_pwm_min);
}