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
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int dev_queue_xmit (struct sk_buff*) ; 

__attribute__((used)) static int arp_xmit_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
	return dev_queue_xmit(skb);
}