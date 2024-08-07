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
struct w1_slave {int dummy; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct bin_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  scalar_t__ loff_t ;
typedef  int int16_t ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 struct w1_slave* kobj_to_w1_slave (struct kobject*) ; 
 int snprintf (char*,size_t,char*,int) ; 
 scalar_t__ w1_ds2438_get_temperature (struct w1_slave*,int*) ; 

__attribute__((used)) static ssize_t temperature_read(struct file *filp, struct kobject *kobj,
				struct bin_attribute *bin_attr, char *buf,
				loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	int ret;
	int16_t temp;

	if (off != 0)
		return 0;
	if (!buf)
		return -EINVAL;

	if (w1_ds2438_get_temperature(sl, &temp) == 0) {
		ret = snprintf(buf, count, "%i\n", temp);
	} else
		ret = -EIO;

	return ret;
}