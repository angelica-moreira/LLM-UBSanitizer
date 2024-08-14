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
struct generic_pm_domain {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 struct generic_pm_domain* dev_to_genpd_safe (struct device*) ; 
 int genpd_remove_device (struct generic_pm_domain*,struct device*) ; 

int pm_genpd_remove_device(struct device *dev)
{
	struct generic_pm_domain *genpd = dev_to_genpd_safe(dev);

	if (!genpd)
		return -EINVAL;

	return genpd_remove_device(genpd, dev);
}