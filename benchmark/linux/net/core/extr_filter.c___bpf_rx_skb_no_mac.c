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
struct sk_buff {struct net_device* dev; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int ____dev_forward_skb (struct net_device*,struct sk_buff*) ; 
 scalar_t__ likely (int) ; 
 int netif_rx (struct sk_buff*) ; 

__attribute__((used)) static inline int __bpf_rx_skb_no_mac(struct net_device *dev,
				      struct sk_buff *skb)
{
	int ret = ____dev_forward_skb(dev, skb);

	if (likely(!ret)) {
		skb->dev = dev;
		ret = netif_rx(skb);
	}

	return ret;
}