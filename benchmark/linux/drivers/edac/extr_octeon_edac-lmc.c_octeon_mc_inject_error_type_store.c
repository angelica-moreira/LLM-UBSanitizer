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
struct octeon_lmc_pvt {int error_type; } ;
struct mem_ctl_info {struct octeon_lmc_pvt* pvt_info; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 
 struct mem_ctl_info* to_mci (struct device*) ; 

__attribute__((used)) static ssize_t octeon_mc_inject_error_type_store(struct device *dev,
					  struct device_attribute *attr,
					  const char *data,
					  size_t count)
{
	struct mem_ctl_info *mci = to_mci(dev);
	struct octeon_lmc_pvt *pvt = mci->pvt_info;

	if (!strncmp(data, "single", 6))
		pvt->error_type = 1;
	else if (!strncmp(data, "double", 6))
		pvt->error_type = 2;

	return count;
}