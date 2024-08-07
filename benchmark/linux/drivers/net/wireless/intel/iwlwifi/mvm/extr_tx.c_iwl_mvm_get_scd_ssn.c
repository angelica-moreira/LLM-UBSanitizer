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
typedef  int u32 ;
struct iwl_mvm_tx_resp {int frame_count; } ;
struct iwl_mvm {int dummy; } ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 scalar_t__ iwl_mvm_get_agg_status (struct iwl_mvm*,struct iwl_mvm_tx_resp*) ; 
 int le32_to_cpup (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline u32 iwl_mvm_get_scd_ssn(struct iwl_mvm *mvm,
				      struct iwl_mvm_tx_resp *tx_resp)
{
	return le32_to_cpup((__le32 *)iwl_mvm_get_agg_status(mvm, tx_resp) +
			    tx_resp->frame_count) & 0xfff;
}