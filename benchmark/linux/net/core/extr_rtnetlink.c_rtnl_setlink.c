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
struct sk_buff {int /*<<< orphan*/  sk; } ;
struct nlmsghdr {int dummy; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct net_device {int dummy; } ;
struct net {int dummy; } ;
struct ifinfomsg {scalar_t__ ifi_index; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 size_t IFLA_IFNAME ; 
 int /*<<< orphan*/  IFLA_MAX ; 
 int IFNAMSIZ ; 
 struct net_device* __dev_get_by_index (struct net*,scalar_t__) ; 
 struct net_device* __dev_get_by_name (struct net*,char*) ; 
 int do_setlink (struct sk_buff*,struct net_device*,struct ifinfomsg*,struct netlink_ext_ack*,struct nlattr**,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ifla_policy ; 
 int /*<<< orphan*/  nla_strlcpy (char*,struct nlattr*,int) ; 
 struct ifinfomsg* nlmsg_data (struct nlmsghdr*) ; 
 int nlmsg_parse_deprecated (struct nlmsghdr*,int,struct nlattr**,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct netlink_ext_ack*) ; 
 int rtnl_ensure_unique_netns (struct nlattr**,struct netlink_ext_ack*,int) ; 
 struct net* sock_net (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rtnl_setlink(struct sk_buff *skb, struct nlmsghdr *nlh,
			struct netlink_ext_ack *extack)
{
	struct net *net = sock_net(skb->sk);
	struct ifinfomsg *ifm;
	struct net_device *dev;
	int err;
	struct nlattr *tb[IFLA_MAX+1];
	char ifname[IFNAMSIZ];

	err = nlmsg_parse_deprecated(nlh, sizeof(*ifm), tb, IFLA_MAX,
				     ifla_policy, extack);
	if (err < 0)
		goto errout;

	err = rtnl_ensure_unique_netns(tb, extack, false);
	if (err < 0)
		goto errout;

	if (tb[IFLA_IFNAME])
		nla_strlcpy(ifname, tb[IFLA_IFNAME], IFNAMSIZ);
	else
		ifname[0] = '\0';

	err = -EINVAL;
	ifm = nlmsg_data(nlh);
	if (ifm->ifi_index > 0)
		dev = __dev_get_by_index(net, ifm->ifi_index);
	else if (tb[IFLA_IFNAME])
		dev = __dev_get_by_name(net, ifname);
	else
		goto errout;

	if (dev == NULL) {
		err = -ENODEV;
		goto errout;
	}

	err = do_setlink(skb, dev, ifm, extack, tb, ifname, 0);
errout:
	return err;
}