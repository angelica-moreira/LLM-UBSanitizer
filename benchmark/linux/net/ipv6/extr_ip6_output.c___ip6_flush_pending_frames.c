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
struct sk_buff_head {int dummy; } ;
struct sk_buff {int dummy; } ;
struct inet_cork_full {int dummy; } ;
struct inet6_cork {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IP6_INC_STATS (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IPSTATS_MIB_OUTDISCARDS ; 
 struct sk_buff* __skb_dequeue_tail (struct sk_buff_head*) ; 
 int /*<<< orphan*/  ip6_cork_release (struct inet_cork_full*,struct inet6_cork*) ; 
 int /*<<< orphan*/  ip6_dst_idev (scalar_t__) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 scalar_t__ skb_dst (struct sk_buff*) ; 
 int /*<<< orphan*/  sock_net (struct sock*) ; 

__attribute__((used)) static void __ip6_flush_pending_frames(struct sock *sk,
				       struct sk_buff_head *queue,
				       struct inet_cork_full *cork,
				       struct inet6_cork *v6_cork)
{
	struct sk_buff *skb;

	while ((skb = __skb_dequeue_tail(queue)) != NULL) {
		if (skb_dst(skb))
			IP6_INC_STATS(sock_net(sk), ip6_dst_idev(skb_dst(skb)),
				      IPSTATS_MIB_OUTDISCARDS);
		kfree_skb(skb);
	}

	ip6_cork_release(cork, v6_cork);
}