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
struct ath_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MCI_LNA_TAKE ; 
 int /*<<< orphan*/  ar9003_mci_send_message (struct ath_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int,int,int) ; 

__attribute__((used)) static void ar9003_mci_send_lna_take(struct ath_hw *ah, bool wait_done)
{
	u32 payload = 0x70000000;

	ar9003_mci_send_message(ah, MCI_LNA_TAKE, 0, &payload, 1,
				wait_done, false);
}