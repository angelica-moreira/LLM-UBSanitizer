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
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  do_sas_phy_reset (struct device*,size_t,int) ; 

__attribute__((used)) static ssize_t
store_sas_hard_reset(struct device *dev, struct device_attribute *attr,
		     const char *buf, size_t count)
{
	return do_sas_phy_reset(dev, count, 1);
}