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
struct ipv6_pinfo {int /*<<< orphan*/  ipv6_fl_list; } ;
struct ipv6_fl_socklist {int /*<<< orphan*/  next; struct ip6_flowlabel* fl; } ;
struct ip6_flowlabel {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ip6_sk_fl_lock ; 
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ ,struct ipv6_fl_socklist*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void fl_link(struct ipv6_pinfo *np, struct ipv6_fl_socklist *sfl,
		struct ip6_flowlabel *fl)
{
	spin_lock_bh(&ip6_sk_fl_lock);
	sfl->fl = fl;
	sfl->next = np->ipv6_fl_list;
	rcu_assign_pointer(np->ipv6_fl_list, sfl);
	spin_unlock_bh(&ip6_sk_fl_lock);
}