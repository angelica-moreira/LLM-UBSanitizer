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
struct fwnet_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fwnet_broadcast_stop (struct fwnet_device*) ; 
 struct fwnet_device* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 

__attribute__((used)) static int fwnet_stop(struct net_device *net)
{
	struct fwnet_device *dev = netdev_priv(net);

	netif_stop_queue(net);
	fwnet_broadcast_stop(dev);

	return 0;
}