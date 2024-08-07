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
struct ehea_port {int full_duplex; int /*<<< orphan*/  port_speed; int /*<<< orphan*/  netdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  EHEA_SPEED_AUTONEG ; 
 int ehea_set_portspeed (struct ehea_port*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netdev_info (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*) ; 
 struct ehea_port* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int ehea_nway_reset(struct net_device *dev)
{
	struct ehea_port *port = netdev_priv(dev);
	int ret;

	ret = ehea_set_portspeed(port, EHEA_SPEED_AUTONEG);

	if (!ret)
		netdev_info(port->netdev,
			    "Port speed successfully set: %dMbps %s Duplex\n",
			    port->port_speed,
			    port->full_duplex == 1 ? "Full" : "Half");
	return ret;
}