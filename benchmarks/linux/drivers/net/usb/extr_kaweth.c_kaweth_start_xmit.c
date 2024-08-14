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
struct sk_buff {int /*<<< orphan*/  len; } ;
struct TYPE_2__ {int /*<<< orphan*/  tx_bytes; int /*<<< orphan*/  tx_packets; int /*<<< orphan*/  tx_errors; } ;
struct net_device {TYPE_1__ stats; int /*<<< orphan*/  dev; } ;
struct kaweth_device {int /*<<< orphan*/  device_lock; int /*<<< orphan*/  tx_urb; scalar_t__ end; int /*<<< orphan*/  dev; struct sk_buff* tx_skb; int /*<<< orphan*/  status; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 scalar_t__ IS_BLOCKED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NETDEV_TX_OK ; 
 int /*<<< orphan*/ * __skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  dev_kfree_skb_irq (struct sk_buff*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  kaweth_async_set_rx_mode (struct kaweth_device*) ; 
 int /*<<< orphan*/  kaweth_usb_transmit_complete ; 
 struct kaweth_device* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 scalar_t__ skb_cow_head (struct sk_buff*,int) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_fill_bulk_urb (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct kaweth_device*) ; 
 int /*<<< orphan*/  usb_sndbulkpipe (int /*<<< orphan*/ ,int) ; 
 int usb_submit_urb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static netdev_tx_t kaweth_start_xmit(struct sk_buff *skb,
					   struct net_device *net)
{
	struct kaweth_device *kaweth = netdev_priv(net);
	__le16 *private_header;

	int res;

	spin_lock_irq(&kaweth->device_lock);

	kaweth_async_set_rx_mode(kaweth);
	netif_stop_queue(net);
	if (IS_BLOCKED(kaweth->status)) {
		goto skip;
	}

	/* We now decide whether we can put our special header into the sk_buff */
	if (skb_cow_head(skb, 2)) {
		net->stats.tx_errors++;
		netif_start_queue(net);
		spin_unlock_irq(&kaweth->device_lock);
		dev_kfree_skb_any(skb);
		return NETDEV_TX_OK;
	}

	private_header = __skb_push(skb, 2);
	*private_header = cpu_to_le16(skb->len-2);
	kaweth->tx_skb = skb;

	usb_fill_bulk_urb(kaweth->tx_urb,
		      kaweth->dev,
		      usb_sndbulkpipe(kaweth->dev, 2),
		      private_header,
		      skb->len,
		      kaweth_usb_transmit_complete,
		      kaweth);
	kaweth->end = 0;

	if((res = usb_submit_urb(kaweth->tx_urb, GFP_ATOMIC)))
	{
		dev_warn(&net->dev, "kaweth failed tx_urb %d\n", res);
skip:
		net->stats.tx_errors++;

		netif_start_queue(net);
		dev_kfree_skb_irq(skb);
	}
	else
	{
		net->stats.tx_packets++;
		net->stats.tx_bytes += skb->len;
	}

	spin_unlock_irq(&kaweth->device_lock);

	return NETDEV_TX_OK;
}