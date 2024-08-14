#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
struct list_head {int dummy; } ;
struct TYPE_2__ {struct list_head upper; } ;
struct net_device {scalar_t__ upper_level; TYPE_1__ adj_list; } ;

/* Variables and functions */
 struct net_device* __netdev_next_upper_dev (struct net_device*,struct list_head**,int*) ; 

__attribute__((used)) static u8 __netdev_upper_depth(struct net_device *dev)
{
	struct net_device *udev;
	struct list_head *iter;
	u8 max_depth = 0;
	bool ignore;

	for (iter = &dev->adj_list.upper,
	     udev = __netdev_next_upper_dev(dev, &iter, &ignore);
	     udev;
	     udev = __netdev_next_upper_dev(dev, &iter, &ignore)) {
		if (ignore)
			continue;
		if (max_depth < udev->upper_level)
			max_depth = udev->upper_level;
	}

	return max_depth;
}