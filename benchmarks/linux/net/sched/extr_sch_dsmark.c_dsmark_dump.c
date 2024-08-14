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
struct nlattr {int dummy; } ;
struct dsmark_qdisc_data {scalar_t__ indices; scalar_t__ default_index; scalar_t__ set_tc_index; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 int EMSGSIZE ; 
 scalar_t__ NO_DEFAULT_INDEX ; 
 int /*<<< orphan*/  TCA_DSMARK_DEFAULT_INDEX ; 
 int /*<<< orphan*/  TCA_DSMARK_INDICES ; 
 int /*<<< orphan*/  TCA_DSMARK_SET_TC_INDEX ; 
 int /*<<< orphan*/  TCA_OPTIONS ; 
 int /*<<< orphan*/  nla_nest_cancel (struct sk_buff*,struct nlattr*) ; 
 int nla_nest_end (struct sk_buff*,struct nlattr*) ; 
 struct nlattr* nla_nest_start_noflag (struct sk_buff*,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_flag (struct sk_buff*,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_u16 (struct sk_buff*,int /*<<< orphan*/ ,scalar_t__) ; 
 struct dsmark_qdisc_data* qdisc_priv (struct Qdisc*) ; 

__attribute__((used)) static int dsmark_dump(struct Qdisc *sch, struct sk_buff *skb)
{
	struct dsmark_qdisc_data *p = qdisc_priv(sch);
	struct nlattr *opts = NULL;

	opts = nla_nest_start_noflag(skb, TCA_OPTIONS);
	if (opts == NULL)
		goto nla_put_failure;
	if (nla_put_u16(skb, TCA_DSMARK_INDICES, p->indices))
		goto nla_put_failure;

	if (p->default_index != NO_DEFAULT_INDEX &&
	    nla_put_u16(skb, TCA_DSMARK_DEFAULT_INDEX, p->default_index))
		goto nla_put_failure;

	if (p->set_tc_index &&
	    nla_put_flag(skb, TCA_DSMARK_SET_TC_INDEX))
		goto nla_put_failure;

	return nla_nest_end(skb, opts);

nla_put_failure:
	nla_nest_cancel(skb, opts);
	return -EMSGSIZE;
}