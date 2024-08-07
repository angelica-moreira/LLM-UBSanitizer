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
struct net_device {int dummy; } ;
struct cfg80211_registered_device {int /*<<< orphan*/  wiphy; TYPE_1__* ops; } ;
struct cfg80211_chan_def {int dummy; } ;
struct TYPE_2__ {int (* tdls_channel_switch ) (int /*<<< orphan*/ *,struct net_device*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,struct cfg80211_chan_def*) ;} ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ *,struct net_device*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,struct cfg80211_chan_def*) ; 
 int /*<<< orphan*/  trace_rdev_return_int (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  trace_rdev_tdls_channel_switch (int /*<<< orphan*/ *,struct net_device*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,struct cfg80211_chan_def*) ; 

__attribute__((used)) static inline int
rdev_tdls_channel_switch(struct cfg80211_registered_device *rdev,
			 struct net_device *dev, const u8 *addr,
			 u8 oper_class, struct cfg80211_chan_def *chandef)
{
	int ret;

	trace_rdev_tdls_channel_switch(&rdev->wiphy, dev, addr, oper_class,
				       chandef);
	ret = rdev->ops->tdls_channel_switch(&rdev->wiphy, dev, addr,
					     oper_class, chandef);
	trace_rdev_return_int(&rdev->wiphy, ret);
	return ret;
}