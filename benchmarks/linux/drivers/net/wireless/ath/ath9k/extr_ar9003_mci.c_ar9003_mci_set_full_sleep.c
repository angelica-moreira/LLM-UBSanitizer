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
struct ath9k_hw_mci {scalar_t__ bt_state; int ready; int /*<<< orphan*/  halted_bt_gpm; } ;
struct TYPE_2__ {struct ath9k_hw_mci mci; } ;
struct ath_hw {TYPE_1__ btcoex_hw; } ;

/* Variables and functions */
 scalar_t__ MCI_BT_SLEEP ; 
 int /*<<< orphan*/  MCI_STATE_ENABLE ; 
 int /*<<< orphan*/  ar9003_mci_send_coex_halt_bt_gpm (struct ath_hw*,int,int) ; 
 scalar_t__ ar9003_mci_state (struct ath_hw*,int /*<<< orphan*/ ) ; 

void ar9003_mci_set_full_sleep(struct ath_hw *ah)
{
	struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;

	if (ar9003_mci_state(ah, MCI_STATE_ENABLE) &&
	    (mci->bt_state != MCI_BT_SLEEP) &&
	    !mci->halted_bt_gpm) {
		ar9003_mci_send_coex_halt_bt_gpm(ah, true, true);
	}

	mci->ready = false;
}