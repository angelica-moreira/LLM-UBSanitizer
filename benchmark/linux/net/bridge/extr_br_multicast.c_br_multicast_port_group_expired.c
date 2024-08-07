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
struct timer_list {int dummy; } ;
struct net_bridge_port_group {int flags; int /*<<< orphan*/  mglist; int /*<<< orphan*/  timer; TYPE_1__* port; } ;
struct net_bridge {int /*<<< orphan*/  multicast_lock; int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {struct net_bridge* br; } ;

/* Variables and functions */
 int MDB_PG_FLAGS_PERMANENT ; 
 int /*<<< orphan*/  br_multicast_del_pg (struct net_bridge*,struct net_bridge_port_group*) ; 
 struct net_bridge_port_group* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ hlist_unhashed (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  netif_running (int /*<<< orphan*/ ) ; 
 struct net_bridge_port_group* pg ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timer ; 
 scalar_t__ timer_pending (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void br_multicast_port_group_expired(struct timer_list *t)
{
	struct net_bridge_port_group *pg = from_timer(pg, t, timer);
	struct net_bridge *br = pg->port->br;

	spin_lock(&br->multicast_lock);
	if (!netif_running(br->dev) || timer_pending(&pg->timer) ||
	    hlist_unhashed(&pg->mglist) || pg->flags & MDB_PG_FLAGS_PERMANENT)
		goto out;

	br_multicast_del_pg(br, pg);

out:
	spin_unlock(&br->multicast_lock);
}