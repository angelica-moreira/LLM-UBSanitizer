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
struct activity_data {int invert; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 struct activity_data* led_trigger_get_drvdata (struct device*) ; 

__attribute__((used)) static ssize_t led_invert_store(struct device *dev,
                                struct device_attribute *attr,
                                const char *buf, size_t size)
{
	struct activity_data *activity_data = led_trigger_get_drvdata(dev);
	unsigned long state;
	int ret;

	ret = kstrtoul(buf, 0, &state);
	if (ret)
		return ret;

	activity_data->invert = !!state;

	return size;
}