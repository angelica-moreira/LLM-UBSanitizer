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
struct rocker_port {int dummy; } ;
struct net_device {int dummy; } ;
struct ethtool_link_ksettings {int dummy; } ;

/* Variables and functions */
 struct rocker_port* netdev_priv (struct net_device*) ; 
 int rocker_cmd_set_port_settings_ethtool (struct rocker_port*,struct ethtool_link_ksettings const*) ; 

__attribute__((used)) static int
rocker_port_set_link_ksettings(struct net_device *dev,
			       const struct ethtool_link_ksettings *ecmd)
{
	struct rocker_port *rocker_port = netdev_priv(dev);

	return rocker_cmd_set_port_settings_ethtool(rocker_port, ecmd);
}