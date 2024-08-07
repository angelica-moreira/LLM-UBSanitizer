#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u16 ;
struct sk_buff {int dummy; } ;
struct net_device {TYPE_1__* ieee80211_ptr; } ;
struct genl_info {scalar_t__ snd_portid; int /*<<< orphan*/ * attrs; struct net_device** user_ptr; } ;
struct cfg80211_registered_device {TYPE_1__* ieee80211_ptr; } ;
struct TYPE_3__ {scalar_t__ conn_owner_nlportid; scalar_t__ iftype; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int EPERM ; 
 size_t NL80211_ATTR_REASON_CODE ; 
 scalar_t__ NL80211_IFTYPE_P2P_CLIENT ; 
 scalar_t__ NL80211_IFTYPE_STATION ; 
 scalar_t__ WLAN_REASON_DEAUTH_LEAVING ; 
 int cfg80211_disconnect (struct net_device*,struct net_device*,scalar_t__,int) ; 
 scalar_t__ nla_get_u16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wdev_lock (TYPE_1__*) ; 
 int /*<<< orphan*/  wdev_unlock (TYPE_1__*) ; 

__attribute__((used)) static int nl80211_disconnect(struct sk_buff *skb, struct genl_info *info)
{
	struct cfg80211_registered_device *rdev = info->user_ptr[0];
	struct net_device *dev = info->user_ptr[1];
	u16 reason;
	int ret;

	if (dev->ieee80211_ptr->conn_owner_nlportid &&
	    dev->ieee80211_ptr->conn_owner_nlportid != info->snd_portid)
		return -EPERM;

	if (!info->attrs[NL80211_ATTR_REASON_CODE])
		reason = WLAN_REASON_DEAUTH_LEAVING;
	else
		reason = nla_get_u16(info->attrs[NL80211_ATTR_REASON_CODE]);

	if (reason == 0)
		return -EINVAL;

	if (dev->ieee80211_ptr->iftype != NL80211_IFTYPE_STATION &&
	    dev->ieee80211_ptr->iftype != NL80211_IFTYPE_P2P_CLIENT)
		return -EOPNOTSUPP;

	wdev_lock(dev->ieee80211_ptr);
	ret = cfg80211_disconnect(rdev, dev, reason, true);
	wdev_unlock(dev->ieee80211_ptr);
	return ret;
}