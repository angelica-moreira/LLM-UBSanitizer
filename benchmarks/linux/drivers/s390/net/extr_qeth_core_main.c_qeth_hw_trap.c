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
struct qeth_trap_id {int dummy; } ;
struct TYPE_3__ {int type; int action; int options; int ext; scalar_t__ cdata; } ;
struct TYPE_4__ {TYPE_1__ diagass; } ;
struct qeth_ipa_cmd {TYPE_2__ data; } ;
struct qeth_cmd_buffer {int dummy; } ;
struct qeth_card {int dummy; } ;
typedef  enum qeth_diags_trap_action { ____Placeholder_qeth_diags_trap_action } qeth_diags_trap_action ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  QETH_CARD_TEXT (struct qeth_card*,int,char*) ; 
 int /*<<< orphan*/  QETH_DIAGS_CMD_TRAP ; 
#define  QETH_DIAGS_TRAP_ARM 130 
#define  QETH_DIAGS_TRAP_CAPTURE 129 
#define  QETH_DIAGS_TRAP_DISARM 128 
 struct qeth_ipa_cmd* __ipa_cmd (struct qeth_cmd_buffer*) ; 
 struct qeth_cmd_buffer* qeth_get_diag_cmd (struct qeth_card*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  qeth_get_trap_id (struct qeth_card*,struct qeth_trap_id*) ; 
 int /*<<< orphan*/  qeth_hw_trap_cb ; 
 int qeth_send_ipa_cmd (struct qeth_card*,struct qeth_cmd_buffer*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int qeth_hw_trap(struct qeth_card *card, enum qeth_diags_trap_action action)
{
	struct qeth_cmd_buffer *iob;
	struct qeth_ipa_cmd *cmd;

	QETH_CARD_TEXT(card, 2, "diagtrap");
	iob = qeth_get_diag_cmd(card, QETH_DIAGS_CMD_TRAP, 64);
	if (!iob)
		return -ENOMEM;
	cmd = __ipa_cmd(iob);
	cmd->data.diagass.type = 1;
	cmd->data.diagass.action = action;
	switch (action) {
	case QETH_DIAGS_TRAP_ARM:
		cmd->data.diagass.options = 0x0003;
		cmd->data.diagass.ext = 0x00010000 +
			sizeof(struct qeth_trap_id);
		qeth_get_trap_id(card,
			(struct qeth_trap_id *)cmd->data.diagass.cdata);
		break;
	case QETH_DIAGS_TRAP_DISARM:
		cmd->data.diagass.options = 0x0001;
		break;
	case QETH_DIAGS_TRAP_CAPTURE:
		break;
	}
	return qeth_send_ipa_cmd(card, iob, qeth_hw_trap_cb, NULL);
}