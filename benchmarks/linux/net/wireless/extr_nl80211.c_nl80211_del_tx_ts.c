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
typedef  int /*<<< orphan*/  u8 ;
struct wireless_dev {int dummy; } ;
struct sk_buff {int dummy; } ;
struct net_device {struct wireless_dev* ieee80211_ptr; } ;
struct genl_info {int /*<<< orphan*/ * attrs; struct net_device** user_ptr; } ;
struct cfg80211_registered_device {struct wireless_dev* ieee80211_ptr; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t NL80211_ATTR_MAC ; 
 size_t NL80211_ATTR_TSID ; 
 int /*<<< orphan*/ * nla_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nla_get_u8 (int /*<<< orphan*/ ) ; 
 int rdev_del_tx_ts (struct net_device*,struct net_device*,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  wdev_lock (struct wireless_dev*) ; 
 int /*<<< orphan*/  wdev_unlock (struct wireless_dev*) ; 

__attribute__((used)) static int nl80211_del_tx_ts(struct sk_buff *skb, struct genl_info *info)
{
	struct cfg80211_registered_device *rdev = info->user_ptr[0];
	struct net_device *dev = info->user_ptr[1];
	struct wireless_dev *wdev = dev->ieee80211_ptr;
	const u8 *peer;
	u8 tsid;
	int err;

	if (!info->attrs[NL80211_ATTR_TSID] || !info->attrs[NL80211_ATTR_MAC])
		return -EINVAL;

	tsid = nla_get_u8(info->attrs[NL80211_ATTR_TSID]);
	peer = nla_data(info->attrs[NL80211_ATTR_MAC]);

	wdev_lock(wdev);
	err = rdev_del_tx_ts(rdev, dev, tsid, peer);
	wdev_unlock(wdev);

	return err;
}