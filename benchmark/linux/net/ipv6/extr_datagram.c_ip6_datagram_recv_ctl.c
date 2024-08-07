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
struct msghdr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ip6_datagram_recv_common_ctl (struct sock*,struct msghdr*,struct sk_buff*) ; 
 int /*<<< orphan*/  ip6_datagram_recv_specific_ctl (struct sock*,struct msghdr*,struct sk_buff*) ; 

void ip6_datagram_recv_ctl(struct sock *sk, struct msghdr *msg,
			  struct sk_buff *skb)
{
	ip6_datagram_recv_common_ctl(sk, msg, skb);
	ip6_datagram_recv_specific_ctl(sk, msg, skb);
}