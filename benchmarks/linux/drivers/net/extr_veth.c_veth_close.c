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
struct veth_priv {scalar_t__ _xdp_prog; int /*<<< orphan*/  peer; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct veth_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_off (struct net_device*) ; 
 struct net_device* rtnl_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  veth_disable_xdp (struct net_device*) ; 

__attribute__((used)) static int veth_close(struct net_device *dev)
{
	struct veth_priv *priv = netdev_priv(dev);
	struct net_device *peer = rtnl_dereference(priv->peer);

	netif_carrier_off(dev);
	if (peer)
		netif_carrier_off(peer);

	if (priv->_xdp_prog)
		veth_disable_xdp(dev);

	return 0;
}