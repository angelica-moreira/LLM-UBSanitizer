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
struct layer2 {int dummy; } ;
struct FsmInst {struct layer2* userdata; } ;

/* Variables and functions */
 int DM ; 
 int /*<<< orphan*/  RSP ; 
 int get_PollFlag (struct layer2*,struct sk_buff*) ; 
 int /*<<< orphan*/  send_uframe (struct layer2*,struct sk_buff*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
l2_send_DM(struct FsmInst *fi, int event, void *arg)
{
	struct layer2 *l2 = fi->userdata;
	struct sk_buff *skb = arg;

	send_uframe(l2, skb, DM | get_PollFlag(l2, skb), RSP);
}