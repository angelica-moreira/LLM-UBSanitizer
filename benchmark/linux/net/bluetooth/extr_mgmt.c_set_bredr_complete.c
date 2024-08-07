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
typedef  int /*<<< orphan*/  u16 ;
struct mgmt_pending_cmd {int /*<<< orphan*/  sk; int /*<<< orphan*/  opcode; int /*<<< orphan*/  index; } ;
struct hci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_DBG (char*,scalar_t__) ; 
 int /*<<< orphan*/  HCI_BREDR_ENABLED ; 
 int /*<<< orphan*/  MGMT_OP_SET_BREDR ; 
 int /*<<< orphan*/  hci_dev_clear_flag (struct hci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hci_dev_lock (struct hci_dev*) ; 
 int /*<<< orphan*/  hci_dev_unlock (struct hci_dev*) ; 
 int /*<<< orphan*/  mgmt_cmd_status (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  mgmt_pending_remove (struct mgmt_pending_cmd*) ; 
 scalar_t__ mgmt_status (scalar_t__) ; 
 int /*<<< orphan*/  new_settings (struct hci_dev*,int /*<<< orphan*/ ) ; 
 struct mgmt_pending_cmd* pending_find (int /*<<< orphan*/ ,struct hci_dev*) ; 
 int /*<<< orphan*/  send_settings_rsp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hci_dev*) ; 

__attribute__((used)) static void set_bredr_complete(struct hci_dev *hdev, u8 status, u16 opcode)
{
	struct mgmt_pending_cmd *cmd;

	BT_DBG("status 0x%02x", status);

	hci_dev_lock(hdev);

	cmd = pending_find(MGMT_OP_SET_BREDR, hdev);
	if (!cmd)
		goto unlock;

	if (status) {
		u8 mgmt_err = mgmt_status(status);

		/* We need to restore the flag if related HCI commands
		 * failed.
		 */
		hci_dev_clear_flag(hdev, HCI_BREDR_ENABLED);

		mgmt_cmd_status(cmd->sk, cmd->index, cmd->opcode, mgmt_err);
	} else {
		send_settings_rsp(cmd->sk, MGMT_OP_SET_BREDR, hdev);
		new_settings(hdev, cmd->sk);
	}

	mgmt_pending_remove(cmd);

unlock:
	hci_dev_unlock(hdev);
}