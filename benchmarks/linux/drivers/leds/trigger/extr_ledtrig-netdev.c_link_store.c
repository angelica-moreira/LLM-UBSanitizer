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
 int /*<<< orphan*/  NETDEV_ATTR_LINK ; 
 int /*<<< orphan*/  netdev_led_attr_store (struct device*,char const*,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t link_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t size)
{
	return netdev_led_attr_store(dev, buf, size, NETDEV_ATTR_LINK);
}