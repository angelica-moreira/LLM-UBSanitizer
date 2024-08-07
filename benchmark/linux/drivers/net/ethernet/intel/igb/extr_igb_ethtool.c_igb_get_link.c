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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct e1000_mac_info {int get_link_status; } ;
struct TYPE_2__ {struct e1000_mac_info mac; } ;
struct igb_adapter {TYPE_1__ hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  igb_has_link (struct igb_adapter*) ; 
 struct igb_adapter* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_ok (struct net_device*) ; 

__attribute__((used)) static u32 igb_get_link(struct net_device *netdev)
{
	struct igb_adapter *adapter = netdev_priv(netdev);
	struct e1000_mac_info *mac = &adapter->hw.mac;

	/* If the link is not reported up to netdev, interrupts are disabled,
	 * and so the physical link state may have changed since we last
	 * looked. Set get_link_status to make sure that the true link
	 * state is interrogated, rather than pulling a cached and possibly
	 * stale link state from the driver.
	 */
	if (!netif_carrier_ok(netdev))
		mac->get_link_status = 1;

	return igb_has_link(adapter);
}