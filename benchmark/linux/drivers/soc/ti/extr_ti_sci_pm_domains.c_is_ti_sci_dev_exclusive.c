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
typedef  int /*<<< orphan*/  u8 ;
struct ti_sci_genpd_dev_data {int /*<<< orphan*/  exclusive; } ;
struct generic_pm_domain_data {struct ti_sci_genpd_dev_data* data; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct generic_pm_domain_data* dev_gpd_data (struct device*) ; 

__attribute__((used)) static u8 is_ti_sci_dev_exclusive(struct device *dev)
{
	struct generic_pm_domain_data *genpd_data = dev_gpd_data(dev);
	struct ti_sci_genpd_dev_data *sci_dev_data = genpd_data->data;

	return sci_dev_data->exclusive;
}