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
struct device {int dummy; } ;
struct attribute_group {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 struct device* ERR_PTR (int /*<<< orphan*/ ) ; 
 struct device* __hwmon_device_register (struct device*,char const*,void*,int /*<<< orphan*/ *,struct attribute_group const**) ; 

struct device *
hwmon_device_register_with_groups(struct device *dev, const char *name,
				  void *drvdata,
				  const struct attribute_group **groups)
{
	if (!name)
		return ERR_PTR(-EINVAL);

	return __hwmon_device_register(dev, name, drvdata, NULL, groups);
}