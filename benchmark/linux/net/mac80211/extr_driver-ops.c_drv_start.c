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
struct ieee80211_local {int started; int /*<<< orphan*/  hw; TYPE_1__* ops; } ;
struct TYPE_2__ {int (* start ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int EALREADY ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  might_sleep () ; 
 int /*<<< orphan*/  smp_mb () ; 
 int stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_drv_return_int (struct ieee80211_local*,int) ; 
 int /*<<< orphan*/  trace_drv_start (struct ieee80211_local*) ; 

int drv_start(struct ieee80211_local *local)
{
	int ret;

	might_sleep();

	if (WARN_ON(local->started))
		return -EALREADY;

	trace_drv_start(local);
	local->started = true;
	/* allow rx frames */
	smp_mb();
	ret = local->ops->start(&local->hw);
	trace_drv_return_int(local, ret);

	if (ret)
		local->started = false;

	return ret;
}