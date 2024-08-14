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
struct gpio_fan_data {int /*<<< orphan*/  alarm_gpio; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct gpio_fan_data* dev_get_drvdata (struct device*) ; 
 int gpiod_get_value_cansleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t fan1_alarm_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct gpio_fan_data *fan_data = dev_get_drvdata(dev);

	return sprintf(buf, "%d\n",
		       gpiod_get_value_cansleep(fan_data->alarm_gpio));
}