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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  scalar_t__ uint32_t ;
struct scsi_qla_host {int /*<<< orphan*/  host_no; } ;
struct scsi_lun {int dummy; } ;
struct ddb_entry {scalar_t__ fw_ddb_index; } ;
typedef  int /*<<< orphan*/  mbox_sts ;
typedef  int /*<<< orphan*/  mbox_cmd ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG2 (int /*<<< orphan*/ ) ; 
 scalar_t__ MBOX_CMD_LUN_RESET ; 
 int MBOX_REG_COUNT ; 
 scalar_t__ MBOX_STS_COMMAND_COMPLETE ; 
 scalar_t__ MBOX_STS_COMMAND_ERROR ; 
 int QLA_ERROR ; 
 int QLA_SUCCESS ; 
 scalar_t__ cpu_to_le32 (scalar_t__) ; 
 int /*<<< orphan*/  int_to_scsilun (int /*<<< orphan*/ ,struct scsi_lun*) ; 
 int /*<<< orphan*/  memset (scalar_t__**,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qla4xxx_mailbox_command (struct scsi_qla_host*,int,int,scalar_t__*,scalar_t__*) ; 

int qla4xxx_reset_lun(struct scsi_qla_host * ha, struct ddb_entry * ddb_entry,
		      uint64_t lun)
{
	uint32_t mbox_cmd[MBOX_REG_COUNT];
	uint32_t mbox_sts[MBOX_REG_COUNT];
	uint32_t scsi_lun[2];
	int status = QLA_SUCCESS;

	DEBUG2(printk("scsi%ld:%d:%llu: lun reset issued\n", ha->host_no,
		      ddb_entry->fw_ddb_index, lun));

	/*
	 * Send lun reset command to ISP, so that the ISP will return all
	 * outstanding requests with RESET status
	 */
	memset(&mbox_cmd, 0, sizeof(mbox_cmd));
	memset(&mbox_sts, 0, sizeof(mbox_sts));
	int_to_scsilun(lun, (struct scsi_lun *) scsi_lun);

	mbox_cmd[0] = MBOX_CMD_LUN_RESET;
	mbox_cmd[1] = ddb_entry->fw_ddb_index;
	/* FW expects LUN bytes 0-3 in Incoming Mailbox 2
	 * (LUN byte 0 is LSByte, byte 3 is MSByte) */
	mbox_cmd[2] = cpu_to_le32(scsi_lun[0]);
	/* FW expects LUN bytes 4-7 in Incoming Mailbox 3
	 * (LUN byte 4 is LSByte, byte 7 is MSByte) */
	mbox_cmd[3] = cpu_to_le32(scsi_lun[1]);
	mbox_cmd[5] = 0x01;	/* Immediate Command Enable */

	qla4xxx_mailbox_command(ha, MBOX_REG_COUNT, 1, &mbox_cmd[0], &mbox_sts[0]);
	if (mbox_sts[0] != MBOX_STS_COMMAND_COMPLETE &&
	    mbox_sts[0] != MBOX_STS_COMMAND_ERROR)
		status = QLA_ERROR;

	return status;
}