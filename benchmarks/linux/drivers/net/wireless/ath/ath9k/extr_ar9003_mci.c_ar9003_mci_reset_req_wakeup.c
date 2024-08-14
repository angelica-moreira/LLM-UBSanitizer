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
struct ath_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AR_MCI_COMMAND2 ; 
 int /*<<< orphan*/  AR_MCI_COMMAND2_RESET_REQ_WAKEUP ; 
 int /*<<< orphan*/  REG_RMW_FIELD (struct ath_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void ar9003_mci_reset_req_wakeup(struct ath_hw *ah)
{
	REG_RMW_FIELD(ah, AR_MCI_COMMAND2,
		      AR_MCI_COMMAND2_RESET_REQ_WAKEUP, 1);
	udelay(1);
	REG_RMW_FIELD(ah, AR_MCI_COMMAND2,
		      AR_MCI_COMMAND2_RESET_REQ_WAKEUP, 0);
}