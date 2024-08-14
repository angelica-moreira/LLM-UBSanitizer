#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct wireless_dev {int /*<<< orphan*/  event_lock; int /*<<< orphan*/  event_list; int /*<<< orphan*/  wiphy; } ;
struct net_device {struct wireless_dev* ieee80211_ptr; } ;
struct ieee80211_channel {int dummy; } ;
struct cfg80211_registered_device {int /*<<< orphan*/  event_work; } ;
struct TYPE_2__ {struct ieee80211_channel* channel; int /*<<< orphan*/  bssid; } ;
struct cfg80211_event {int /*<<< orphan*/  list; TYPE_1__ ij; int /*<<< orphan*/  type; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int /*<<< orphan*/  ETH_ALEN ; 
 int /*<<< orphan*/  EVENT_IBSS_JOINED ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  cfg80211_wq ; 
 struct cfg80211_event* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  trace_cfg80211_ibss_joined (struct net_device*,int /*<<< orphan*/  const*,struct ieee80211_channel*) ; 
 struct cfg80211_registered_device* wiphy_to_rdev (int /*<<< orphan*/ ) ; 

void cfg80211_ibss_joined(struct net_device *dev, const u8 *bssid,
			  struct ieee80211_channel *channel, gfp_t gfp)
{
	struct wireless_dev *wdev = dev->ieee80211_ptr;
	struct cfg80211_registered_device *rdev = wiphy_to_rdev(wdev->wiphy);
	struct cfg80211_event *ev;
	unsigned long flags;

	trace_cfg80211_ibss_joined(dev, bssid, channel);

	if (WARN_ON(!channel))
		return;

	ev = kzalloc(sizeof(*ev), gfp);
	if (!ev)
		return;

	ev->type = EVENT_IBSS_JOINED;
	memcpy(ev->ij.bssid, bssid, ETH_ALEN);
	ev->ij.channel = channel;

	spin_lock_irqsave(&wdev->event_lock, flags);
	list_add_tail(&ev->list, &wdev->event_list);
	spin_unlock_irqrestore(&wdev->event_lock, flags);
	queue_work(cfg80211_wq, &rdev->event_work);
}