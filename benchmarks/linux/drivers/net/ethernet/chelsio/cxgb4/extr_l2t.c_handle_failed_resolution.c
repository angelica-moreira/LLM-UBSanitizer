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
struct l2t_skb_cb {int /*<<< orphan*/  handle; int /*<<< orphan*/  (* arp_err_handler ) (int /*<<< orphan*/ ,struct sk_buff*) ;} ;
struct l2t_entry {int /*<<< orphan*/  lock; int /*<<< orphan*/  arpq; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 struct l2t_skb_cb* L2T_SKB_CB (struct sk_buff*) ; 
 struct sk_buff* __skb_dequeue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,struct sk_buff*) ; 
 int /*<<< orphan*/  t4_ofld_send (struct adapter*,struct sk_buff*) ; 

__attribute__((used)) static void handle_failed_resolution(struct adapter *adap, struct l2t_entry *e)
{
	struct sk_buff *skb;

	while ((skb = __skb_dequeue(&e->arpq)) != NULL) {
		const struct l2t_skb_cb *cb = L2T_SKB_CB(skb);

		spin_unlock(&e->lock);
		if (cb->arp_err_handler)
			cb->arp_err_handler(cb->handle, skb);
		else
			t4_ofld_send(adap, skb);
		spin_lock(&e->lock);
	}
}