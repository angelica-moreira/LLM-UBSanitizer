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
struct netxen_adapter {int /*<<< orphan*/  (* set_multi ) (struct net_device*) ;} ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct netxen_adapter* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  stub1 (struct net_device*) ; 

__attribute__((used)) static void netxen_set_multicast_list(struct net_device *dev)
{
	struct netxen_adapter *adapter = netdev_priv(dev);

	adapter->set_multi(dev);
}