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
struct cpl_set_tcb_rpl {scalar_t__ status; } ;
struct c4iw_dev {int dummy; } ;

/* Variables and functions */
 scalar_t__ CPL_ERR_NONE ; 
 int /*<<< orphan*/  GET_TID (struct cpl_set_tcb_rpl*) ; 
 struct cpl_set_tcb_rpl* cplhdr (struct sk_buff*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  pr_err (char*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int set_tcb_rpl(struct c4iw_dev *dev, struct sk_buff *skb)
{
	struct cpl_set_tcb_rpl *rpl = cplhdr(skb);

	if (rpl->status != CPL_ERR_NONE) {
		pr_err("Unexpected SET_TCB_RPL status %u for tid %u\n",
		       rpl->status, GET_TID(rpl));
	}
	kfree_skb(skb);
	return 0;
}