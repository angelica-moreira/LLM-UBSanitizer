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
typedef  int /*<<< orphan*/  u32 ;
struct iwl_mvm {int dummy; } ;
struct ieee80211_vif {int dummy; } ;

/* Variables and functions */
 int _iwl_mvm_disable_beacon_filter (struct iwl_mvm*,struct ieee80211_vif*,int /*<<< orphan*/ ) ; 

int iwl_mvm_disable_beacon_filter(struct iwl_mvm *mvm,
				  struct ieee80211_vif *vif,
				  u32 flags)
{
	return _iwl_mvm_disable_beacon_filter(mvm, vif, flags);
}