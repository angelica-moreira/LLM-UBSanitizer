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

/* Variables and functions */
 int /*<<< orphan*/  NETDEV_NOTIFY_PEERS ; 
 int /*<<< orphan*/  NETDEV_RESEND_IGMP ; 
 int /*<<< orphan*/  call_netdevice_notifiers (int /*<<< orphan*/ ,struct net_device*) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 

void netdev_notify_peers(struct net_device *dev)
{
	rtnl_lock();
	call_netdevice_notifiers(NETDEV_NOTIFY_PEERS, dev);
	call_netdevice_notifiers(NETDEV_RESEND_IGMP, dev);
	rtnl_unlock();
}