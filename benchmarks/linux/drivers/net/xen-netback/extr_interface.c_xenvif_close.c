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
struct xenvif {int /*<<< orphan*/  status; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VIF_STATUS_CONNECTED ; 
 struct xenvif* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_tx_stop_all_queues (struct net_device*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xenvif_down (struct xenvif*) ; 

__attribute__((used)) static int xenvif_close(struct net_device *dev)
{
	struct xenvif *vif = netdev_priv(dev);
	if (test_bit(VIF_STATUS_CONNECTED, &vif->status))
		xenvif_down(vif);
	netif_tx_stop_all_queues(dev);
	return 0;
}