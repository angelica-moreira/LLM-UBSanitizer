#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int* band_load; } ;
struct TYPE_4__ {TYPE_1__ result; } ;
struct iwl_mvm {TYPE_2__ tcm; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum iwl_mvm_traffic_load { ____Placeholder_iwl_mvm_traffic_load } iwl_mvm_traffic_load ;

/* Variables and functions */

__attribute__((used)) static enum iwl_mvm_traffic_load
iwl_mvm_get_traffic_load_band(struct iwl_mvm *mvm, enum nl80211_band band)
{
	return mvm->tcm.result.band_load[band];
}