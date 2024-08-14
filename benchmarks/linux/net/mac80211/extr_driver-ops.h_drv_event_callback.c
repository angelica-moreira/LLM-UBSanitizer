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
struct ieee80211_sub_if_data {int /*<<< orphan*/  vif; } ;
struct ieee80211_local {int /*<<< orphan*/  hw; TYPE_1__* ops; } ;
struct ieee80211_event {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* event_callback ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct ieee80211_event const*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct ieee80211_event const*) ; 
 int /*<<< orphan*/  trace_drv_event_callback (struct ieee80211_local*,struct ieee80211_sub_if_data*,struct ieee80211_event const*) ; 
 int /*<<< orphan*/  trace_drv_return_void (struct ieee80211_local*) ; 

__attribute__((used)) static inline void drv_event_callback(struct ieee80211_local *local,
				      struct ieee80211_sub_if_data *sdata,
				      const struct ieee80211_event *event)
{
	trace_drv_event_callback(local, sdata, event);
	if (local->ops->event_callback)
		local->ops->event_callback(&local->hw, &sdata->vif, event);
	trace_drv_return_void(local);
}