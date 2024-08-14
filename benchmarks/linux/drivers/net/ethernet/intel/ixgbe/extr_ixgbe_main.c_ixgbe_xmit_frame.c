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
struct sk_buff {int dummy; } ;
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;

/* Variables and functions */
 int /*<<< orphan*/  __ixgbe_xmit_frame (struct sk_buff*,struct net_device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static netdev_tx_t ixgbe_xmit_frame(struct sk_buff *skb,
				    struct net_device *netdev)
{
	return __ixgbe_xmit_frame(skb, netdev, NULL);
}