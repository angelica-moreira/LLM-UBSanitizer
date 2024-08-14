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
struct hsi_msg {int /*<<< orphan*/ * destructor; struct sk_buff* context; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  hsi_free_msg (struct hsi_msg*) ; 
 int /*<<< orphan*/  pr_debug (char*,struct hsi_msg*,struct sk_buff*,struct sk_buff*) ; 

__attribute__((used)) static void ssip_free_data(struct hsi_msg *msg)
{
	struct sk_buff *skb;

	skb = msg->context;
	pr_debug("free data: msg %p context %p skb %p\n", msg, msg->context,
								skb);
	msg->destructor = NULL;
	dev_kfree_skb(skb);
	hsi_free_msg(msg);
}