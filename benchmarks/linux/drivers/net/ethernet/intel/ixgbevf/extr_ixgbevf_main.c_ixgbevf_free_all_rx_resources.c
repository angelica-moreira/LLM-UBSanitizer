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
struct ixgbevf_adapter {int num_rx_queues; TYPE_1__** rx_ring; } ;
struct TYPE_2__ {scalar_t__ desc; } ;

/* Variables and functions */
 int /*<<< orphan*/  ixgbevf_free_rx_resources (TYPE_1__*) ; 

__attribute__((used)) static void ixgbevf_free_all_rx_resources(struct ixgbevf_adapter *adapter)
{
	int i;

	for (i = 0; i < adapter->num_rx_queues; i++)
		if (adapter->rx_ring[i]->desc)
			ixgbevf_free_rx_resources(adapter->rx_ring[i]);
}