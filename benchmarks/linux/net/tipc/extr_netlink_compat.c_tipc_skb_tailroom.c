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
struct sk_buff {int len; } ;

/* Variables and functions */
 int TIPC_SKB_MAX ; 
 int skb_tailroom (struct sk_buff*) ; 

__attribute__((used)) static int tipc_skb_tailroom(struct sk_buff *skb)
{
	int tailroom;
	int limit;

	tailroom = skb_tailroom(skb);
	limit = TIPC_SKB_MAX - skb->len;

	if (tailroom < limit)
		return tailroom;

	return limit;
}