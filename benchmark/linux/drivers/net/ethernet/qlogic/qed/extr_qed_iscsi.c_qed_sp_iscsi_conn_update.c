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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_6__ {int /*<<< orphan*/  flags; int /*<<< orphan*/  op_code; } ;
struct iscsi_conn_update_ramrod_params {void* exp_stat_sn; void* first_seq_length; void* max_send_pdu_length; void* max_recv_pdu_length; void* max_seq_size; int /*<<< orphan*/  flags; void* fw_cid; int /*<<< orphan*/  conn_id; TYPE_3__ hdr; } ;
struct TYPE_5__ {struct iscsi_conn_update_ramrod_params iscsi_conn_update; } ;
struct qed_spq_entry {TYPE_2__ ramrod; } ;
struct qed_spq_comp_cb {int dummy; } ;
struct qed_sp_init_data {int comp_mode; struct qed_spq_comp_cb* p_comp_data; int /*<<< orphan*/  opaque_fid; int /*<<< orphan*/  cid; } ;
struct qed_iscsi_conn {int /*<<< orphan*/  exp_stat_sn; int /*<<< orphan*/  first_seq_length; int /*<<< orphan*/  max_send_pdu_length; int /*<<< orphan*/  max_recv_pdu_length; int /*<<< orphan*/  max_seq_size; int /*<<< orphan*/  update_flag; int /*<<< orphan*/  icid; int /*<<< orphan*/  conn_id; int /*<<< orphan*/  layer_code; } ;
struct TYPE_4__ {int /*<<< orphan*/  opaque_fid; } ;
struct qed_hwfn {TYPE_1__ hw_info; } ;
typedef  int /*<<< orphan*/  init_data ;
typedef  enum spq_mode { ____Placeholder_spq_mode } spq_mode ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  ISCSI_RAMROD_CMD_ID_UPDATE_CONN ; 
 int /*<<< orphan*/  ISCSI_SLOW_PATH_HDR_LAYER_CODE ; 
 int /*<<< orphan*/  PROTOCOLID_ISCSI ; 
 int /*<<< orphan*/  SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct qed_sp_init_data*,int /*<<< orphan*/ ,int) ; 
 int qed_sp_init_request (struct qed_hwfn*,struct qed_spq_entry**,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct qed_sp_init_data*) ; 
 int qed_spq_post (struct qed_hwfn*,struct qed_spq_entry*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int qed_sp_iscsi_conn_update(struct qed_hwfn *p_hwfn,
				    struct qed_iscsi_conn *p_conn,
				    enum spq_mode comp_mode,
				    struct qed_spq_comp_cb *p_comp_addr)
{
	struct iscsi_conn_update_ramrod_params *p_ramrod = NULL;
	struct qed_spq_entry *p_ent = NULL;
	struct qed_sp_init_data init_data;
	int rc = -EINVAL;
	u32 dval;

	/* Get SPQ entry */
	memset(&init_data, 0, sizeof(init_data));
	init_data.cid = p_conn->icid;
	init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
	init_data.comp_mode = comp_mode;
	init_data.p_comp_data = p_comp_addr;

	rc = qed_sp_init_request(p_hwfn, &p_ent,
				 ISCSI_RAMROD_CMD_ID_UPDATE_CONN,
				 PROTOCOLID_ISCSI, &init_data);
	if (rc)
		return rc;

	p_ramrod = &p_ent->ramrod.iscsi_conn_update;
	p_ramrod->hdr.op_code = ISCSI_RAMROD_CMD_ID_UPDATE_CONN;
	SET_FIELD(p_ramrod->hdr.flags,
		  ISCSI_SLOW_PATH_HDR_LAYER_CODE, p_conn->layer_code);

	p_ramrod->conn_id = cpu_to_le16(p_conn->conn_id);
	p_ramrod->fw_cid = cpu_to_le32(p_conn->icid);
	p_ramrod->flags = p_conn->update_flag;
	p_ramrod->max_seq_size = cpu_to_le32(p_conn->max_seq_size);
	dval = p_conn->max_recv_pdu_length;
	p_ramrod->max_recv_pdu_length = cpu_to_le32(dval);
	dval = p_conn->max_send_pdu_length;
	p_ramrod->max_send_pdu_length = cpu_to_le32(dval);
	dval = p_conn->first_seq_length;
	p_ramrod->first_seq_length = cpu_to_le32(dval);
	p_ramrod->exp_stat_sn = cpu_to_le32(p_conn->exp_stat_sn);

	return qed_spq_post(p_hwfn, p_ent, NULL);
}