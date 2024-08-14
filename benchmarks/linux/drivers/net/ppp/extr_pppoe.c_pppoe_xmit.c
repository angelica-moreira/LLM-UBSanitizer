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
struct ppp_channel {scalar_t__ private; } ;

/* Variables and functions */
 int __pppoe_xmit (struct sock*,struct sk_buff*) ; 

__attribute__((used)) static int pppoe_xmit(struct ppp_channel *chan, struct sk_buff *skb)
{
	struct sock *sk = (struct sock *)chan->private;
	return __pppoe_xmit(sk, skb);
}