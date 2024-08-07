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
typedef  scalar_t__ u8 ;
struct net_device {int dummy; } ;
struct be_adapter {int flags; struct net_device* netdev; } ;

/* Variables and functions */
 int BE_FLAGS_LINK_STATUS_INIT ; 
 int /*<<< orphan*/  netdev_info (struct net_device*,char*,char*) ; 
 int /*<<< orphan*/  netif_carrier_off (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_on (struct net_device*) ; 

void be_link_status_update(struct be_adapter *adapter, u8 link_status)
{
	struct net_device *netdev = adapter->netdev;

	if (!(adapter->flags & BE_FLAGS_LINK_STATUS_INIT)) {
		netif_carrier_off(netdev);
		adapter->flags |= BE_FLAGS_LINK_STATUS_INIT;
	}

	if (link_status)
		netif_carrier_on(netdev);
	else
		netif_carrier_off(netdev);

	netdev_info(netdev, "Link is %s\n", link_status ? "Up" : "Down");
}