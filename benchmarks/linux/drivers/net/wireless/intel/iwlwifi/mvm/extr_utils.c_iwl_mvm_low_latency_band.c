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
struct iwl_mvm_low_latency_iter {int* result_per_band; } ;
struct iwl_mvm {int /*<<< orphan*/  hw; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;

/* Variables and functions */
 int /*<<< orphan*/  IEEE80211_IFACE_ITER_NORMAL ; 
 int /*<<< orphan*/  ieee80211_iterate_active_interfaces_atomic (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct iwl_mvm_low_latency_iter*) ; 
 int /*<<< orphan*/  iwl_mvm_ll_iter ; 

bool iwl_mvm_low_latency_band(struct iwl_mvm *mvm, enum nl80211_band band)
{
	struct iwl_mvm_low_latency_iter data = {};

	ieee80211_iterate_active_interfaces_atomic(
			mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
			iwl_mvm_ll_iter, &data);

	return data.result_per_band[band];
}