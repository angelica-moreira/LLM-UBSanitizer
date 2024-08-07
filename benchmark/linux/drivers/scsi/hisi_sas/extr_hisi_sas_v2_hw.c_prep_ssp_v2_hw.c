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
typedef  int u8 ;
typedef  int u32 ;
struct ssp_frame_hdr {int dummy; } ;
struct ssp_command_iu {int dummy; } ;
struct scsi_cmnd {int sc_data_direction; int cmd_len; int /*<<< orphan*/ * cmnd; } ;
struct sas_ssp_task {int task_attr; int task_prio; struct scsi_cmnd* cmd; int /*<<< orphan*/  LUN; } ;
struct sas_task {int total_xfer_len; struct sas_ssp_task ssp_task; int /*<<< orphan*/  scatter; struct domain_device* dev; } ;
struct hisi_sas_tmf_task {int tmf; int tag_of_task_to_be_managed; } ;
struct hisi_sas_slot {int idx; int /*<<< orphan*/  n_elem; struct hisi_sas_tmf_task* tmf; struct hisi_sas_port* port; struct hisi_sas_cmd_hdr* cmd_hdr; struct sas_task* task; } ;
struct hisi_sas_port {int id; } ;
struct hisi_sas_device {int device_id; } ;
struct hisi_sas_cmd_hdr {void* sts_buffer_addr; void* cmd_table_addr; void* data_transfer_len; void* transfer_tags; void* dw2; void* dw1; void* dw0; } ;
struct hisi_hba {int dummy; } ;
struct domain_device {struct hisi_sas_device* lldd_dev; } ;

/* Variables and functions */
 int CMD_HDR_CFL_OFF ; 
 int CMD_HDR_CMD_OFF ; 
 int CMD_HDR_DEV_ID_OFF ; 
 int CMD_HDR_DIR_MSK ; 
 int CMD_HDR_DIR_OFF ; 
 int CMD_HDR_FRAME_TYPE_OFF ; 
 int CMD_HDR_MRFL_OFF ; 
 int CMD_HDR_PORT_OFF ; 
 int CMD_HDR_PRIORITY_OFF ; 
 int CMD_HDR_RESP_REPORT_OFF ; 
 int CMD_HDR_SG_MOD_OFF ; 
 int CMD_HDR_TLR_CTRL_OFF ; 
 int CMD_HDR_VDTL_OFF ; 
 int DIR_NO_DATA ; 
 int DIR_TO_DEVICE ; 
 int DIR_TO_INI ; 
#define  DMA_FROM_DEVICE 131 
#define  DMA_TO_DEVICE 130 
 int HISI_SAS_MAX_SSP_RESP_SZ ; 
#define  TMF_ABORT_TASK 129 
#define  TMF_QUERY_TASK 128 
 void* cpu_to_le32 (int) ; 
 void* cpu_to_le64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hisi_sas_cmd_hdr_addr_dma (struct hisi_sas_slot*) ; 
 int* hisi_sas_cmd_hdr_addr_mem (struct hisi_sas_slot*) ; 
 int /*<<< orphan*/  hisi_sas_status_buf_addr_dma (struct hisi_sas_slot*) ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  prep_prd_sge_v2_hw (struct hisi_hba*,struct hisi_sas_slot*,struct hisi_sas_cmd_hdr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void prep_ssp_v2_hw(struct hisi_hba *hisi_hba,
			  struct hisi_sas_slot *slot)
{
	struct sas_task *task = slot->task;
	struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
	struct domain_device *device = task->dev;
	struct hisi_sas_device *sas_dev = device->lldd_dev;
	struct hisi_sas_port *port = slot->port;
	struct sas_ssp_task *ssp_task = &task->ssp_task;
	struct scsi_cmnd *scsi_cmnd = ssp_task->cmd;
	struct hisi_sas_tmf_task *tmf = slot->tmf;
	int has_data = 0, priority = !!tmf;
	u8 *buf_cmd;
	u32 dw1 = 0, dw2 = 0;

	hdr->dw0 = cpu_to_le32((1 << CMD_HDR_RESP_REPORT_OFF) |
			       (2 << CMD_HDR_TLR_CTRL_OFF) |
			       (port->id << CMD_HDR_PORT_OFF) |
			       (priority << CMD_HDR_PRIORITY_OFF) |
			       (1 << CMD_HDR_CMD_OFF)); /* ssp */

	dw1 = 1 << CMD_HDR_VDTL_OFF;
	if (tmf) {
		dw1 |= 2 << CMD_HDR_FRAME_TYPE_OFF;
		dw1 |= DIR_NO_DATA << CMD_HDR_DIR_OFF;
	} else {
		dw1 |= 1 << CMD_HDR_FRAME_TYPE_OFF;
		switch (scsi_cmnd->sc_data_direction) {
		case DMA_TO_DEVICE:
			has_data = 1;
			dw1 |= DIR_TO_DEVICE << CMD_HDR_DIR_OFF;
			break;
		case DMA_FROM_DEVICE:
			has_data = 1;
			dw1 |= DIR_TO_INI << CMD_HDR_DIR_OFF;
			break;
		default:
			dw1 &= ~CMD_HDR_DIR_MSK;
		}
	}

	/* map itct entry */
	dw1 |= sas_dev->device_id << CMD_HDR_DEV_ID_OFF;
	hdr->dw1 = cpu_to_le32(dw1);

	dw2 = (((sizeof(struct ssp_command_iu) + sizeof(struct ssp_frame_hdr)
	      + 3) / 4) << CMD_HDR_CFL_OFF) |
	      ((HISI_SAS_MAX_SSP_RESP_SZ / 4) << CMD_HDR_MRFL_OFF) |
	      (2 << CMD_HDR_SG_MOD_OFF);
	hdr->dw2 = cpu_to_le32(dw2);

	hdr->transfer_tags = cpu_to_le32(slot->idx);

	if (has_data)
		prep_prd_sge_v2_hw(hisi_hba, slot, hdr, task->scatter,
					slot->n_elem);

	hdr->data_transfer_len = cpu_to_le32(task->total_xfer_len);
	hdr->cmd_table_addr = cpu_to_le64(hisi_sas_cmd_hdr_addr_dma(slot));
	hdr->sts_buffer_addr = cpu_to_le64(hisi_sas_status_buf_addr_dma(slot));

	buf_cmd = hisi_sas_cmd_hdr_addr_mem(slot) +
		sizeof(struct ssp_frame_hdr);

	memcpy(buf_cmd, &task->ssp_task.LUN, 8);
	if (!tmf) {
		buf_cmd[9] = task->ssp_task.task_attr |
				(task->ssp_task.task_prio << 3);
		memcpy(buf_cmd + 12, task->ssp_task.cmd->cmnd,
				task->ssp_task.cmd->cmd_len);
	} else {
		buf_cmd[10] = tmf->tmf;
		switch (tmf->tmf) {
		case TMF_ABORT_TASK:
		case TMF_QUERY_TASK:
			buf_cmd[12] =
				(tmf->tag_of_task_to_be_managed >> 8) & 0xff;
			buf_cmd[13] =
				tmf->tag_of_task_to_be_managed & 0xff;
			break;
		default:
			break;
		}
	}
}