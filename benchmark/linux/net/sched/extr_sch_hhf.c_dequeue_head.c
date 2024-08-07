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
struct wdrr_bucket {struct sk_buff* head; } ;
struct sk_buff {struct sk_buff* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  skb_mark_not_on_list (struct sk_buff*) ; 

__attribute__((used)) static struct sk_buff *dequeue_head(struct wdrr_bucket *bucket)
{
	struct sk_buff *skb = bucket->head;

	bucket->head = skb->next;
	skb_mark_not_on_list(skb);
	return skb;
}