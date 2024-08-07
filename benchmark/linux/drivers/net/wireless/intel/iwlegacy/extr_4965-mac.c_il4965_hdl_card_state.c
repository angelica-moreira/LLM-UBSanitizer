#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_4__ {int /*<<< orphan*/  flags; } ;
struct TYPE_5__ {TYPE_1__ card_state_notif; } ;
struct il_rx_pkt {TYPE_2__ u; } ;
struct il_rx_buf {int dummy; } ;
struct il_priv {unsigned long status; int /*<<< orphan*/  wait_command_queue; TYPE_3__* hw; } ;
struct TYPE_6__ {int /*<<< orphan*/  wiphy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED ; 
 int /*<<< orphan*/  CSR_UCODE_DRV_GP1_CLR ; 
 int /*<<< orphan*/  CSR_UCODE_DRV_GP1_SET ; 
 int CT_CARD_DISABLED ; 
 int /*<<< orphan*/  D_RF_KILL (char*,char*,char*,char*) ; 
 int /*<<< orphan*/  HBUS_TARG_MBX_C ; 
 int /*<<< orphan*/  HBUS_TARG_MBX_C_REG_BIT_CMD_BLOCKED ; 
 int HW_CARD_DISABLED ; 
 int RXON_CARD_DISABLED ; 
 int SW_CARD_DISABLED ; 
 int /*<<< orphan*/  S_RFKILL ; 
 int /*<<< orphan*/  _il_wr (struct il_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  il4965_perform_ct_kill_task (struct il_priv*) ; 
 int /*<<< orphan*/  il_scan_cancel (struct il_priv*) ; 
 int /*<<< orphan*/  il_wr (struct il_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 struct il_rx_pkt* rxb_addr (struct il_rx_buf*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wiphy_rfkill_set_hw_state (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void
il4965_hdl_card_state(struct il_priv *il, struct il_rx_buf *rxb)
{
	struct il_rx_pkt *pkt = rxb_addr(rxb);
	u32 flags = le32_to_cpu(pkt->u.card_state_notif.flags);
	unsigned long status = il->status;

	D_RF_KILL("Card state received: HW:%s SW:%s CT:%s\n",
		  (flags & HW_CARD_DISABLED) ? "Kill" : "On",
		  (flags & SW_CARD_DISABLED) ? "Kill" : "On",
		  (flags & CT_CARD_DISABLED) ? "Reached" : "Not reached");

	if (flags & (SW_CARD_DISABLED | HW_CARD_DISABLED | CT_CARD_DISABLED)) {

		_il_wr(il, CSR_UCODE_DRV_GP1_SET,
		       CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);

		il_wr(il, HBUS_TARG_MBX_C, HBUS_TARG_MBX_C_REG_BIT_CMD_BLOCKED);

		if (!(flags & RXON_CARD_DISABLED)) {
			_il_wr(il, CSR_UCODE_DRV_GP1_CLR,
			       CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);
			il_wr(il, HBUS_TARG_MBX_C,
			      HBUS_TARG_MBX_C_REG_BIT_CMD_BLOCKED);
		}
	}

	if (flags & CT_CARD_DISABLED)
		il4965_perform_ct_kill_task(il);

	if (flags & HW_CARD_DISABLED)
		set_bit(S_RFKILL, &il->status);
	else
		clear_bit(S_RFKILL, &il->status);

	if (!(flags & RXON_CARD_DISABLED))
		il_scan_cancel(il);

	if ((test_bit(S_RFKILL, &status) !=
	     test_bit(S_RFKILL, &il->status)))
		wiphy_rfkill_set_hw_state(il->hw->wiphy,
					  test_bit(S_RFKILL, &il->status));
	else
		wake_up(&il->wait_command_queue);
}