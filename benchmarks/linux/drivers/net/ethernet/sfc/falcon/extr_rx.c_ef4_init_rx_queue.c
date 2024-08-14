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
struct ef4_rx_queue {unsigned int min_fill; unsigned int max_fill; unsigned int fast_fill_trigger; int refill_enabled; scalar_t__ page_recycle_full; scalar_t__ page_recycle_failed; scalar_t__ page_recycle_count; scalar_t__ page_ptr_mask; scalar_t__ page_add; scalar_t__ page_remove; scalar_t__ removed_count; scalar_t__ notified_count; scalar_t__ added_count; struct ef4_nic* efx; } ;
struct ef4_nic {unsigned int rxq_entries; unsigned int rx_pages_per_batch; unsigned int rx_bufs_per_page; int /*<<< orphan*/  net_dev; } ;

/* Variables and functions */
 unsigned int EF4_RXD_HEAD_ROOM ; 
 int /*<<< orphan*/  drv ; 
 int /*<<< orphan*/  ef4_init_rx_recycle_ring (struct ef4_nic*,struct ef4_rx_queue*) ; 
 int /*<<< orphan*/  ef4_nic_init_rx (struct ef4_rx_queue*) ; 
 int /*<<< orphan*/  ef4_rx_queue_index (struct ef4_rx_queue*) ; 
 unsigned int min (scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  netif_dbg (struct ef4_nic*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ rx_refill_threshold ; 

void ef4_init_rx_queue(struct ef4_rx_queue *rx_queue)
{
	struct ef4_nic *efx = rx_queue->efx;
	unsigned int max_fill, trigger, max_trigger;

	netif_dbg(rx_queue->efx, drv, rx_queue->efx->net_dev,
		  "initialising RX queue %d\n", ef4_rx_queue_index(rx_queue));

	/* Initialise ptr fields */
	rx_queue->added_count = 0;
	rx_queue->notified_count = 0;
	rx_queue->removed_count = 0;
	rx_queue->min_fill = -1U;
	ef4_init_rx_recycle_ring(efx, rx_queue);

	rx_queue->page_remove = 0;
	rx_queue->page_add = rx_queue->page_ptr_mask + 1;
	rx_queue->page_recycle_count = 0;
	rx_queue->page_recycle_failed = 0;
	rx_queue->page_recycle_full = 0;

	/* Initialise limit fields */
	max_fill = efx->rxq_entries - EF4_RXD_HEAD_ROOM;
	max_trigger =
		max_fill - efx->rx_pages_per_batch * efx->rx_bufs_per_page;
	if (rx_refill_threshold != 0) {
		trigger = max_fill * min(rx_refill_threshold, 100U) / 100U;
		if (trigger > max_trigger)
			trigger = max_trigger;
	} else {
		trigger = max_trigger;
	}

	rx_queue->max_fill = max_fill;
	rx_queue->fast_fill_trigger = trigger;
	rx_queue->refill_enabled = true;

	/* Set up RX descriptor ring */
	ef4_nic_init_rx(rx_queue);
}