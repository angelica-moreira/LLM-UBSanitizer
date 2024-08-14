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
struct mvpp2_port {int /*<<< orphan*/  phylink; } ;
struct ethtool_pauseparam {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 struct mvpp2_port* netdev_priv (struct net_device*) ; 
 int phylink_ethtool_set_pauseparam (int /*<<< orphan*/ ,struct ethtool_pauseparam*) ; 

__attribute__((used)) static int mvpp2_ethtool_set_pause_param(struct net_device *dev,
					 struct ethtool_pauseparam *pause)
{
	struct mvpp2_port *port = netdev_priv(dev);

	if (!port->phylink)
		return -ENOTSUPP;

	return phylink_ethtool_set_pauseparam(port->phylink, pause);
}