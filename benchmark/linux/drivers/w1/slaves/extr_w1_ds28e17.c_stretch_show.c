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
struct w1_slave {struct w1_f19_data* family_data; } ;
struct w1_f19_data {int stretch; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct w1_slave* dev_to_w1_slave (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t stretch_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	struct w1_slave *sl = dev_to_w1_slave(dev);
	struct w1_f19_data *data = sl->family_data;

	/* Return current stretch value. */
	return sprintf(buf, "%d\n", data->stretch);
}