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
typedef  unsigned long long u64 ;
struct ieee80211_sub_if_data {int /*<<< orphan*/  vif; } ;
struct ieee80211_local {int /*<<< orphan*/  hw; TYPE_1__* ops; } ;
struct TYPE_2__ {unsigned long long (* get_tsf ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  check_sdata_in_driver (struct ieee80211_sub_if_data*) ; 
 int /*<<< orphan*/  might_sleep () ; 
 unsigned long long stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_drv_get_tsf (struct ieee80211_local*,struct ieee80211_sub_if_data*) ; 
 int /*<<< orphan*/  trace_drv_return_u64 (struct ieee80211_local*,unsigned long long) ; 

u64 drv_get_tsf(struct ieee80211_local *local,
		struct ieee80211_sub_if_data *sdata)
{
	u64 ret = -1ULL;

	might_sleep();

	if (!check_sdata_in_driver(sdata))
		return ret;

	trace_drv_get_tsf(local, sdata);
	if (local->ops->get_tsf)
		ret = local->ops->get_tsf(&local->hw, &sdata->vif);
	trace_drv_return_u64(local, ret);
	return ret;
}