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
struct ocelot_port {int /*<<< orphan*/  pvid; int /*<<< orphan*/  ocelot; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct ocelot_port* netdev_priv (struct net_device*) ; 
 int ocelot_mact_forget (int /*<<< orphan*/ ,unsigned char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ocelot_mc_unsync(struct net_device *dev, const unsigned char *addr)
{
	struct ocelot_port *port = netdev_priv(dev);

	return ocelot_mact_forget(port->ocelot, addr, port->pvid);
}