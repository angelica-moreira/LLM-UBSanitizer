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
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int ipoib_vlan_delete (int /*<<< orphan*/ ,int) ; 
 int sscanf (char const*,char*,int*) ; 
 int /*<<< orphan*/  to_net_dev (struct device*) ; 

__attribute__((used)) static ssize_t delete_child(struct device *dev,
			    struct device_attribute *attr,
			    const char *buf, size_t count)
{
	int pkey;
	int ret;

	if (sscanf(buf, "%i", &pkey) != 1)
		return -EINVAL;

	if (pkey < 0 || pkey > 0xffff)
		return -EINVAL;

	ret = ipoib_vlan_delete(to_net_dev(dev), pkey);

	return ret ? ret : count;

}