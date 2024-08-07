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
struct device {struct dev_pm_domain* pm_domain; } ;
struct dev_pm_domain {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN (int,char*) ; 
 scalar_t__ device_is_bound (struct device*) ; 
 int /*<<< orphan*/  device_pm_check_callbacks (struct device*) ; 

void dev_pm_domain_set(struct device *dev, struct dev_pm_domain *pd)
{
	if (dev->pm_domain == pd)
		return;

	WARN(pd && device_is_bound(dev),
	     "PM domains can only be changed for unbound devices\n");
	dev->pm_domain = pd;
	device_pm_check_callbacks(dev);
}