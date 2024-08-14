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
typedef  size_t u32 ;
struct pci_dev {int dummy; } ;
struct nx_host_tx_ring {size_t sw_consumer; int /*<<< orphan*/ * hw_consumer; int /*<<< orphan*/  num_desc; struct netxen_cmd_buffer* cmd_buf_arr; } ;
struct netxen_skb_frag {unsigned long long dma; int /*<<< orphan*/  length; } ;
struct netxen_cmd_buffer {int frag_count; int /*<<< orphan*/ * skb; struct netxen_skb_frag* frag_array; } ;
struct TYPE_2__ {int /*<<< orphan*/  xmitfinished; } ;
struct netxen_adapter {int /*<<< orphan*/  tx_clean_lock; scalar_t__ tx_timeo_cnt; TYPE_1__ stats; struct nx_host_tx_ring* tx_ring; struct net_device* netdev; struct pci_dev* pdev; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int MAX_STATUS_HANDLE ; 
 int /*<<< orphan*/  PCI_DMA_TODEVICE ; 
 scalar_t__ TX_STOP_THRESH ; 
 int /*<<< orphan*/  dev_kfree_skb_any (int /*<<< orphan*/ *) ; 
 size_t get_next_index (size_t,int /*<<< orphan*/ ) ; 
 size_t le32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ netif_carrier_ok (struct net_device*) ; 
 scalar_t__ netif_queue_stopped (struct net_device*) ; 
 scalar_t__ netif_running (struct net_device*) ; 
 int /*<<< orphan*/  netif_wake_queue (struct net_device*) ; 
 scalar_t__ netxen_tx_avail (struct nx_host_tx_ring*) ; 
 int /*<<< orphan*/  pci_unmap_page (struct pci_dev*,unsigned long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_unmap_single (struct pci_dev*,unsigned long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_mb () ; 
 int /*<<< orphan*/  spin_trylock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

int netxen_process_cmd_ring(struct netxen_adapter *adapter)
{
	u32 sw_consumer, hw_consumer;
	int count = 0, i;
	struct netxen_cmd_buffer *buffer;
	struct pci_dev *pdev = adapter->pdev;
	struct net_device *netdev = adapter->netdev;
	struct netxen_skb_frag *frag;
	int done = 0;
	struct nx_host_tx_ring *tx_ring = adapter->tx_ring;

	if (!spin_trylock_bh(&adapter->tx_clean_lock))
		return 1;

	sw_consumer = tx_ring->sw_consumer;
	hw_consumer = le32_to_cpu(*(tx_ring->hw_consumer));

	while (sw_consumer != hw_consumer) {
		buffer = &tx_ring->cmd_buf_arr[sw_consumer];
		if (buffer->skb) {
			frag = &buffer->frag_array[0];
			pci_unmap_single(pdev, frag->dma, frag->length,
					 PCI_DMA_TODEVICE);
			frag->dma = 0ULL;
			for (i = 1; i < buffer->frag_count; i++) {
				frag++;	/* Get the next frag */
				pci_unmap_page(pdev, frag->dma, frag->length,
					       PCI_DMA_TODEVICE);
				frag->dma = 0ULL;
			}

			adapter->stats.xmitfinished++;
			dev_kfree_skb_any(buffer->skb);
			buffer->skb = NULL;
		}

		sw_consumer = get_next_index(sw_consumer, tx_ring->num_desc);
		if (++count >= MAX_STATUS_HANDLE)
			break;
	}

	tx_ring->sw_consumer = sw_consumer;

	if (count && netif_running(netdev)) {
		smp_mb();

		if (netif_queue_stopped(netdev) && netif_carrier_ok(netdev))
			if (netxen_tx_avail(tx_ring) > TX_STOP_THRESH)
				netif_wake_queue(netdev);
		adapter->tx_timeo_cnt = 0;
	}
	/*
	 * If everything is freed up to consumer then check if the ring is full
	 * If the ring is full then check if more needs to be freed and
	 * schedule the call back again.
	 *
	 * This happens when there are 2 CPUs. One could be freeing and the
	 * other filling it. If the ring is full when we get out of here and
	 * the card has already interrupted the host then the host can miss the
	 * interrupt.
	 *
	 * There is still a possible race condition and the host could miss an
	 * interrupt. The card has to take care of this.
	 */
	hw_consumer = le32_to_cpu(*(tx_ring->hw_consumer));
	done = (sw_consumer == hw_consumer);
	spin_unlock_bh(&adapter->tx_clean_lock);

	return done;
}