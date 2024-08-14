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
struct eeepc_laptop {int dummy; } ;
struct eeepc_cpufv {int num; int cur; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 struct eeepc_laptop* dev_get_drvdata (struct device*) ; 
 scalar_t__ get_cpufv (struct eeepc_laptop*,struct eeepc_cpufv*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t cpufv_show(struct device *dev,
			  struct device_attribute *attr,
			  char *buf)
{
	struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
	struct eeepc_cpufv c;

	if (get_cpufv(eeepc, &c))
		return -ENODEV;
	return sprintf(buf, "%#x\n", (c.num << 8) | c.cur);
}