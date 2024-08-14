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
struct fm10k_intfc {int num_rx_queues; int /*<<< orphan*/ * rx_ring; int /*<<< orphan*/  netdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  fm10k_free_rx_resources (int /*<<< orphan*/ ) ; 
 int fm10k_setup_rx_resources (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_err (struct fm10k_intfc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  probe ; 

__attribute__((used)) static int fm10k_setup_all_rx_resources(struct fm10k_intfc *interface)
{
	int i, err;

	for (i = 0; i < interface->num_rx_queues; i++) {
		err = fm10k_setup_rx_resources(interface->rx_ring[i]);
		if (!err)
			continue;

		netif_err(interface, probe, interface->netdev,
			  "Allocation for Rx Queue %u failed\n", i);
		goto err_setup_rx;
	}

	return 0;
err_setup_rx:
	/* rewind the index freeing the rings as we go */
	while (i--)
		fm10k_free_rx_resources(interface->rx_ring[i]);
	return err;
}