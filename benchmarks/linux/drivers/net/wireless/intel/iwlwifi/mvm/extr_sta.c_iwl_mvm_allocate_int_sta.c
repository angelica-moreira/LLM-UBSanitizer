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
struct iwl_mvm_int_sta {size_t sta_id; int type; int /*<<< orphan*/  tfd_queue_msk; } ;
struct iwl_mvm {int /*<<< orphan*/ * fw_id_to_mac_id; int /*<<< orphan*/  status; } ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum iwl_sta_type { ____Placeholder_iwl_sta_type } iwl_sta_type ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int ENOSPC ; 
 int /*<<< orphan*/  ERR_PTR (int /*<<< orphan*/ ) ; 
 size_t IWL_MVM_INVALID_STA ; 
 int /*<<< orphan*/  IWL_MVM_STATUS_IN_HW_RESTART ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 size_t iwl_mvm_find_free_sta_id (struct iwl_mvm*,int) ; 
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int iwl_mvm_allocate_int_sta(struct iwl_mvm *mvm,
			     struct iwl_mvm_int_sta *sta,
			     u32 qmask, enum nl80211_iftype iftype,
			     enum iwl_sta_type type)
{
	if (!test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status) ||
	    sta->sta_id == IWL_MVM_INVALID_STA) {
		sta->sta_id = iwl_mvm_find_free_sta_id(mvm, iftype);
		if (WARN_ON_ONCE(sta->sta_id == IWL_MVM_INVALID_STA))
			return -ENOSPC;
	}

	sta->tfd_queue_msk = qmask;
	sta->type = type;

	/* put a non-NULL value so iterating over the stations won't stop */
	rcu_assign_pointer(mvm->fw_id_to_mac_id[sta->sta_id], ERR_PTR(-EINVAL));
	return 0;
}