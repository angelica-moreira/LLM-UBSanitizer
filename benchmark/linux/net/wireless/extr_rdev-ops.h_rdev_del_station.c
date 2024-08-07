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
struct station_del_parameters {int dummy; } ;
struct net_device {int dummy; } ;
struct cfg80211_registered_device {int /*<<< orphan*/  wiphy; TYPE_1__* ops; } ;
struct TYPE_2__ {int (* del_station ) (int /*<<< orphan*/ *,struct net_device*,struct station_del_parameters*) ;} ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ *,struct net_device*,struct station_del_parameters*) ; 
 int /*<<< orphan*/  trace_rdev_del_station (int /*<<< orphan*/ *,struct net_device*,struct station_del_parameters*) ; 
 int /*<<< orphan*/  trace_rdev_return_int (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline int rdev_del_station(struct cfg80211_registered_device *rdev,
				   struct net_device *dev,
				   struct station_del_parameters *params)
{
	int ret;
	trace_rdev_del_station(&rdev->wiphy, dev, params);
	ret = rdev->ops->del_station(&rdev->wiphy, dev, params);
	trace_rdev_return_int(&rdev->wiphy, ret);
	return ret;
}