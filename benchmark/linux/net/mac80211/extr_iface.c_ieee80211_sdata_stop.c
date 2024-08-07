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
struct ieee80211_sub_if_data {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  SDATA_STATE_RUNNING ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  ieee80211_do_stop (struct ieee80211_sub_if_data*,int) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void ieee80211_sdata_stop(struct ieee80211_sub_if_data *sdata)
{
	if (WARN_ON_ONCE(!test_bit(SDATA_STATE_RUNNING, &sdata->state)))
		return;
	ieee80211_do_stop(sdata, true);
}