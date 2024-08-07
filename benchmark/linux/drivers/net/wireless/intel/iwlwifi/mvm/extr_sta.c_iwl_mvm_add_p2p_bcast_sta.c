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
struct iwl_mvm_int_sta {int dummy; } ;
struct iwl_mvm_vif {struct iwl_mvm_int_sta bcast_sta; } ;
struct iwl_mvm {int /*<<< orphan*/  mutex; } ;
struct ieee80211_vif {int dummy; } ;

/* Variables and functions */
 int iwl_mvm_alloc_bcast_sta (struct iwl_mvm*,struct ieee80211_vif*) ; 
 int /*<<< orphan*/  iwl_mvm_dealloc_int_sta (struct iwl_mvm*,struct iwl_mvm_int_sta*) ; 
 int iwl_mvm_send_add_bcast_sta (struct iwl_mvm*,struct ieee80211_vif*) ; 
 struct iwl_mvm_vif* iwl_mvm_vif_from_mac80211 (struct ieee80211_vif*) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 

int iwl_mvm_add_p2p_bcast_sta(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
	struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
	struct iwl_mvm_int_sta *bsta = &mvmvif->bcast_sta;
	int ret;

	lockdep_assert_held(&mvm->mutex);

	ret = iwl_mvm_alloc_bcast_sta(mvm, vif);
	if (ret)
		return ret;

	ret = iwl_mvm_send_add_bcast_sta(mvm, vif);

	if (ret)
		iwl_mvm_dealloc_int_sta(mvm, bsta);

	return ret;
}