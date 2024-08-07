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
typedef  scalar_t__ u8 ;
struct iwl_mvm_vif {struct iwl_mvm* mvm; } ;
struct iwl_mvm {int /*<<< orphan*/  mutex; } ;
struct ieee80211_vif {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  LOW_LATENCY_DEBUGFS_FORCE ; 
 int /*<<< orphan*/  LOW_LATENCY_DEBUGFS_FORCE_ENABLE ; 
 scalar_t__ LOW_LATENCY_FORCE_ON ; 
 scalar_t__ LOW_LATENCY_FORCE_UNSET ; 
 scalar_t__ NUM_LOW_LATENCY_FORCE ; 
 int /*<<< orphan*/  iwl_mvm_update_low_latency (struct iwl_mvm*,struct ieee80211_vif*,int,int /*<<< orphan*/ ) ; 
 struct iwl_mvm_vif* iwl_mvm_vif_from_mac80211 (struct ieee80211_vif*) ; 
 int kstrtou8 (char*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t
iwl_dbgfs_low_latency_force_write(struct ieee80211_vif *vif, char *buf,
				  size_t count, loff_t *ppos)
{
	struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
	struct iwl_mvm *mvm = mvmvif->mvm;
	u8 value;
	int ret;

	ret = kstrtou8(buf, 0, &value);
	if (ret)
		return ret;

	if (value > NUM_LOW_LATENCY_FORCE)
		return -EINVAL;

	mutex_lock(&mvm->mutex);
	if (value == LOW_LATENCY_FORCE_UNSET) {
		iwl_mvm_update_low_latency(mvm, vif, false,
					   LOW_LATENCY_DEBUGFS_FORCE);
		iwl_mvm_update_low_latency(mvm, vif, false,
					   LOW_LATENCY_DEBUGFS_FORCE_ENABLE);
	} else {
		iwl_mvm_update_low_latency(mvm, vif,
					   value == LOW_LATENCY_FORCE_ON,
					   LOW_LATENCY_DEBUGFS_FORCE);
		iwl_mvm_update_low_latency(mvm, vif, true,
					   LOW_LATENCY_DEBUGFS_FORCE_ENABLE);
	}
	mutex_unlock(&mvm->mutex);
	return count;
}