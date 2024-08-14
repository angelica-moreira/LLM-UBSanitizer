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
struct mISDNchannel {int /*<<< orphan*/  st; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  __net_timestamp (struct sk_buff*) ; 
 int /*<<< orphan*/  _queue_message (int /*<<< orphan*/ ,struct sk_buff*) ; 

__attribute__((used)) static int
l1_receive(struct mISDNchannel *ch, struct sk_buff *skb)
{
	if (!ch->st)
		return -ENODEV;
	__net_timestamp(skb);
	_queue_message(ch->st, skb);
	return 0;
}