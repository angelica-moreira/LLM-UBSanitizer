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
struct vt8231_data {int* in_max; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct vt8231_data* vt8231_update_device (struct device*) ; 

__attribute__((used)) static ssize_t in5_max_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct vt8231_data *data = vt8231_update_device(dev);

	return sprintf(buf, "%d\n",
		(((data->in_max[5] - 3) * 10000 * 54) / (958 * 34)));
}