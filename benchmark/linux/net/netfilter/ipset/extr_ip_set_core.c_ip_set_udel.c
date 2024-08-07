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
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct nlmsghdr {int dummy; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPSET_DEL ; 
 int ip_set_ad (struct net*,struct sock*,struct sk_buff*,int /*<<< orphan*/ ,struct nlmsghdr const*,struct nlattr const* const*,struct netlink_ext_ack*) ; 

__attribute__((used)) static int ip_set_udel(struct net *net, struct sock *ctnl,
		       struct sk_buff *skb, const struct nlmsghdr *nlh,
		       const struct nlattr * const attr[],
		       struct netlink_ext_ack *extack)
{
	return ip_set_ad(net, ctnl, skb,
			 IPSET_DEL, nlh, attr, extack);
}