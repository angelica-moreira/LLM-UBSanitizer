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
struct net_device {scalar_t__ ifindex; } ;

/* Variables and functions */
 scalar_t__ dev_get_iflink (struct net_device*) ; 
 scalar_t__ netif_carrier_ok (struct net_device*) ; 
 scalar_t__ netif_is_lag_master (struct net_device*) ; 
 scalar_t__ netif_is_lag_port (struct net_device*) ; 
 int /*<<< orphan*/  netif_running (struct net_device*) ; 
 scalar_t__ qdisc_tx_changing (struct net_device*) ; 

__attribute__((used)) static bool linkwatch_urgent_event(struct net_device *dev)
{
	if (!netif_running(dev))
		return false;

	if (dev->ifindex != dev_get_iflink(dev))
		return true;

	if (netif_is_lag_port(dev) || netif_is_lag_master(dev))
		return true;

	return netif_carrier_ok(dev) &&	qdisc_tx_changing(dev);
}