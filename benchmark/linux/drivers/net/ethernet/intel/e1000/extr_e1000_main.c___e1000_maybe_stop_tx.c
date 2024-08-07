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
struct e1000_tx_ring {int dummy; } ;
struct e1000_adapter {int /*<<< orphan*/  restart_queue; struct e1000_tx_ring* tx_ring; } ;

/* Variables and functions */
 int E1000_DESC_UNUSED (struct e1000_tx_ring*) ; 
 int EBUSY ; 
 scalar_t__ likely (int) ; 
 struct e1000_adapter* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 int /*<<< orphan*/  smp_mb () ; 

__attribute__((used)) static int __e1000_maybe_stop_tx(struct net_device *netdev, int size)
{
	struct e1000_adapter *adapter = netdev_priv(netdev);
	struct e1000_tx_ring *tx_ring = adapter->tx_ring;

	netif_stop_queue(netdev);
	/* Herbert's original patch had:
	 *  smp_mb__after_netif_stop_queue();
	 * but since that doesn't exist yet, just open code it.
	 */
	smp_mb();

	/* We need to check again in a case another CPU has just
	 * made room available.
	 */
	if (likely(E1000_DESC_UNUSED(tx_ring) < size))
		return -EBUSY;

	/* A reprieve! */
	netif_start_queue(netdev);
	++adapter->restart_queue;
	return 0;
}