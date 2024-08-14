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
struct tcphdr {int doff; } ;
struct sock {int dummy; } ;
struct sk_buff {scalar_t__ data; } ;

/* Variables and functions */
 int sk_filter_trim_cap (struct sock*,struct sk_buff*,int) ; 

int tcp_filter(struct sock *sk, struct sk_buff *skb)
{
	struct tcphdr *th = (struct tcphdr *)skb->data;

	return sk_filter_trim_cap(sk, skb, th->doff * 4);
}