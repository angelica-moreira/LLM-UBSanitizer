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
struct TYPE_2__ {int /*<<< orphan*/  lower; int /*<<< orphan*/  upper; } ;
struct net_device {TYPE_1__ adj_list; } ;

/* Variables and functions */
 int __netdev_adjacent_dev_link_lists (struct net_device*,struct net_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,void*,int) ; 

__attribute__((used)) static int __netdev_adjacent_dev_link_neighbour(struct net_device *dev,
						struct net_device *upper_dev,
						void *private, bool master)
{
	return __netdev_adjacent_dev_link_lists(dev, upper_dev,
						&dev->adj_list.upper,
						&upper_dev->adj_list.lower,
						private, master);
}