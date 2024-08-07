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
typedef  int /*<<< orphan*/  u16 ;
struct sk_buff_head {int dummy; } ;
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __skb_unlink (struct sk_buff*,struct sk_buff_head*) ; 
 int /*<<< orphan*/  buf_seqno (struct sk_buff*) ; 
 scalar_t__ less_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct sk_buff* skb_peek (struct sk_buff_head*) ; 

__attribute__((used)) static inline struct sk_buff *__tipc_skb_dequeue(struct sk_buff_head *list,
						 u16 seqno)
{
	struct sk_buff *skb = skb_peek(list);

	if (skb && less_eq(buf_seqno(skb), seqno)) {
		__skb_unlink(skb, list);
		return skb;
	}
	return NULL;
}