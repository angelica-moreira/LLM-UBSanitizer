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
struct tc_skbprio_qopt {int /*<<< orphan*/  limit; } ;
struct sk_buff {int len; } ;
struct Qdisc {int /*<<< orphan*/  limit; } ;
typedef  int /*<<< orphan*/  opt ;

/* Variables and functions */
 int /*<<< orphan*/  TCA_OPTIONS ; 
 scalar_t__ nla_put (struct sk_buff*,int /*<<< orphan*/ ,int,struct tc_skbprio_qopt*) ; 

__attribute__((used)) static int skbprio_dump(struct Qdisc *sch, struct sk_buff *skb)
{
	struct tc_skbprio_qopt opt;

	opt.limit = sch->limit;

	if (nla_put(skb, TCA_OPTIONS, sizeof(opt), &opt))
		return -1;

	return skb->len;
}