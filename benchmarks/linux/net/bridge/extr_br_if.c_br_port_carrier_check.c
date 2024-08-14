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
struct net_bridge_port {int flags; scalar_t__ state; int /*<<< orphan*/  path_cost; struct net_bridge* br; struct net_device* dev; } ;
struct net_bridge {int /*<<< orphan*/  lock; struct net_device* dev; } ;

/* Variables and functions */
 int BR_ADMIN_COST ; 
 scalar_t__ BR_STATE_DISABLED ; 
 int /*<<< orphan*/  br_stp_disable_port (struct net_bridge_port*) ; 
 int /*<<< orphan*/  br_stp_enable_port (struct net_bridge_port*) ; 
 scalar_t__ netif_oper_up (struct net_device*) ; 
 scalar_t__ netif_running (struct net_device*) ; 
 int /*<<< orphan*/  port_cost (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

void br_port_carrier_check(struct net_bridge_port *p, bool *notified)
{
	struct net_device *dev = p->dev;
	struct net_bridge *br = p->br;

	if (!(p->flags & BR_ADMIN_COST) &&
	    netif_running(dev) && netif_oper_up(dev))
		p->path_cost = port_cost(dev);

	*notified = false;
	if (!netif_running(br->dev))
		return;

	spin_lock_bh(&br->lock);
	if (netif_running(dev) && netif_oper_up(dev)) {
		if (p->state == BR_STATE_DISABLED) {
			br_stp_enable_port(p);
			*notified = true;
		}
	} else {
		if (p->state != BR_STATE_DISABLED) {
			br_stp_disable_port(p);
			*notified = true;
		}
	}
	spin_unlock_bh(&br->lock);
}