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
typedef  int /*<<< orphan*/  u32 ;
struct dpot_data {int /*<<< orphan*/  update_lock; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 struct dpot_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dpot_write (struct dpot_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t sysfs_do_cmd(struct device *dev,
			    struct device_attribute *attr,
			    const char *buf, size_t count, u32 reg)
{
	struct dpot_data *data = dev_get_drvdata(dev);

	mutex_lock(&data->update_lock);
	dpot_write(data, reg, 0);
	mutex_unlock(&data->update_lock);

	return count;
}