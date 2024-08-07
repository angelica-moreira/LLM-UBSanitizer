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
struct sockaddr {int /*<<< orphan*/  sa_data; } ;
struct ocelot_port {int /*<<< orphan*/  pvid; struct ocelot* ocelot; } ;
struct ocelot {int dummy; } ;
struct net_device {int /*<<< orphan*/  dev_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENTRYTYPE_LOCKED ; 
 int /*<<< orphan*/  PGID_CPU ; 
 int /*<<< orphan*/  ether_addr_copy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ocelot_port* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  ocelot_mact_forget (struct ocelot*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocelot_mact_learn (struct ocelot*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ocelot_port_set_mac_address(struct net_device *dev, void *p)
{
	struct ocelot_port *port = netdev_priv(dev);
	struct ocelot *ocelot = port->ocelot;
	const struct sockaddr *addr = p;

	/* Learn the new net device MAC address in the mac table. */
	ocelot_mact_learn(ocelot, PGID_CPU, addr->sa_data, port->pvid,
			  ENTRYTYPE_LOCKED);
	/* Then forget the previous one. */
	ocelot_mact_forget(ocelot, dev->dev_addr, port->pvid);

	ether_addr_copy(dev->dev_addr, addr->sa_data);
	return 0;
}