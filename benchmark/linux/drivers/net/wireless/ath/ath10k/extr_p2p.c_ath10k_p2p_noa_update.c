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
struct wmi_p2p_noa_info {int dummy; } ;
struct ath10k_vif {struct ath10k* ar; } ;
struct ath10k {int /*<<< orphan*/  data_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ath10k_p2p_noa_update (struct ath10k_vif*,struct wmi_p2p_noa_info const*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

void ath10k_p2p_noa_update(struct ath10k_vif *arvif,
			   const struct wmi_p2p_noa_info *noa)
{
	struct ath10k *ar = arvif->ar;

	spin_lock_bh(&ar->data_lock);
	__ath10k_p2p_noa_update(arvif, noa);
	spin_unlock_bh(&ar->data_lock);
}