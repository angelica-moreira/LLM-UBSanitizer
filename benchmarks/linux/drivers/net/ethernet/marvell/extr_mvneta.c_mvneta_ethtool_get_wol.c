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
struct mvneta_port {int /*<<< orphan*/  phylink; } ;
struct ethtool_wolinfo {int dummy; } ;

/* Variables and functions */
 struct mvneta_port* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  phylink_ethtool_get_wol (int /*<<< orphan*/ ,struct ethtool_wolinfo*) ; 

__attribute__((used)) static void mvneta_ethtool_get_wol(struct net_device *dev,
				   struct ethtool_wolinfo *wol)
{
	struct mvneta_port *pp = netdev_priv(dev);

	phylink_ethtool_get_wol(pp->phylink, wol);
}