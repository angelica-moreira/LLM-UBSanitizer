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
struct sk_buff {scalar_t__ data; } ;

/* Variables and functions */
 int SH_ETH_RX_ALIGN ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,int) ; 

__attribute__((used)) static void sh_eth_set_receive_align(struct sk_buff *skb)
{
	uintptr_t reserve = (uintptr_t)skb->data & (SH_ETH_RX_ALIGN - 1);

	if (reserve)
		skb_reserve(skb, SH_ETH_RX_ALIGN - reserve);
}