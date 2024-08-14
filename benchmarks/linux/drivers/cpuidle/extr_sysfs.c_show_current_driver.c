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
struct cpuidle_driver {char* name; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpuidle_driver_lock ; 
 struct cpuidle_driver* cpuidle_get_driver () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 

__attribute__((used)) static ssize_t show_current_driver(struct device *dev,
				   struct device_attribute *attr,
				   char *buf)
{
	ssize_t ret;
	struct cpuidle_driver *drv;

	spin_lock(&cpuidle_driver_lock);
	drv = cpuidle_get_driver();
	if (drv)
		ret = sprintf(buf, "%s\n", drv->name);
	else
		ret = sprintf(buf, "none\n");
	spin_unlock(&cpuidle_driver_lock);

	return ret;
}