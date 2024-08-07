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
struct net_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ __netdev_update_features (struct net_device*) ; 
 int /*<<< orphan*/  netdev_features_change (struct net_device*) ; 

void netdev_update_features(struct net_device *dev)
{
	if (__netdev_update_features(dev))
		netdev_features_change(dev);
}