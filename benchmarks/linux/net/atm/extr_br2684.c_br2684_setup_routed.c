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
struct net_device {int hard_header_len; int flags; int tx_queue_len; int /*<<< orphan*/  type; int /*<<< orphan*/  max_mtu; scalar_t__ min_mtu; int /*<<< orphan*/  mtu; scalar_t__ addr_len; int /*<<< orphan*/ * netdev_ops; } ;
struct br2684_dev {int /*<<< orphan*/  brvccs; struct net_device* net_dev; } ;
typedef  int /*<<< orphan*/  llc_oui_ipv4 ;

/* Variables and functions */
 int /*<<< orphan*/  ARPHRD_PPP ; 
 struct br2684_dev* BRPRIV (struct net_device*) ; 
 int /*<<< orphan*/  ETH_DATA_LEN ; 
 int /*<<< orphan*/  ETH_MAX_MTU ; 
 int IFF_MULTICAST ; 
 int IFF_NOARP ; 
 int IFF_POINTOPOINT ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  br2684_netdev_ops_routed ; 

__attribute__((used)) static void br2684_setup_routed(struct net_device *netdev)
{
	struct br2684_dev *brdev = BRPRIV(netdev);

	brdev->net_dev = netdev;
	netdev->hard_header_len = sizeof(llc_oui_ipv4); /* worst case */
	netdev->netdev_ops = &br2684_netdev_ops_routed;
	netdev->addr_len = 0;
	netdev->mtu = ETH_DATA_LEN;
	netdev->min_mtu = 0;
	netdev->max_mtu = ETH_MAX_MTU;
	netdev->type = ARPHRD_PPP;
	netdev->flags = IFF_POINTOPOINT | IFF_NOARP | IFF_MULTICAST;
	netdev->tx_queue_len = 100;
	INIT_LIST_HEAD(&brdev->brvccs);
}