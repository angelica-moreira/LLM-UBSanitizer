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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct TYPE_3__ {scalar_t__ eth_fp_hsi_minor; } ;
struct TYPE_4__ {TYPE_1__ vfdev_info; } ;
struct qed_iov_vf_mbx {int /*<<< orphan*/ * offset; scalar_t__ reply_virt; } ;
struct qed_vf_info {TYPE_2__ acquire; struct qed_iov_vf_mbx vf_mbx; } ;
struct qed_ptt {int dummy; } ;
struct qed_hwfn {int dummy; } ;
struct pfvf_start_queue_resp_tlv {int /*<<< orphan*/  offset; } ;
struct pfvf_def_resp_tlv {int dummy; } ;
struct channel_list_end_tlv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CHANNEL_TLV_LIST_END ; 
 int /*<<< orphan*/  CHANNEL_TLV_START_TXQ ; 
 int /*<<< orphan*/  DQ_DEMS_LEGACY ; 
 scalar_t__ ETH_HSI_VER_NO_PKT_LEN_TUNN ; 
 int /*<<< orphan*/  PFVF_STATUS_SUCCESS ; 
 struct pfvf_start_queue_resp_tlv* qed_add_tlv (struct qed_hwfn*,int /*<<< orphan*/ **,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  qed_db_addr_vf (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qed_iov_send_response (struct qed_hwfn*,struct qed_ptt*,struct qed_vf_info*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void qed_iov_vf_mbx_start_txq_resp(struct qed_hwfn *p_hwfn,
					  struct qed_ptt *p_ptt,
					  struct qed_vf_info *p_vf,
					  u32 cid, u8 status)
{
	struct qed_iov_vf_mbx *mbx = &p_vf->vf_mbx;
	struct pfvf_start_queue_resp_tlv *p_tlv;
	bool b_legacy = false;
	u16 length;

	mbx->offset = (u8 *)mbx->reply_virt;

	/* Taking a bigger struct instead of adding a TLV to list was a
	 * mistake, but one which we're now stuck with, as some older
	 * clients assume the size of the previous response.
	 */
	if (p_vf->acquire.vfdev_info.eth_fp_hsi_minor ==
	    ETH_HSI_VER_NO_PKT_LEN_TUNN)
		b_legacy = true;

	if (!b_legacy)
		length = sizeof(*p_tlv);
	else
		length = sizeof(struct pfvf_def_resp_tlv);

	p_tlv = qed_add_tlv(p_hwfn, &mbx->offset, CHANNEL_TLV_START_TXQ,
			    length);
	qed_add_tlv(p_hwfn, &mbx->offset, CHANNEL_TLV_LIST_END,
		    sizeof(struct channel_list_end_tlv));

	/* Update the TLV with the response */
	if ((status == PFVF_STATUS_SUCCESS) && !b_legacy)
		p_tlv->offset = qed_db_addr_vf(cid, DQ_DEMS_LEGACY);

	qed_iov_send_response(p_hwfn, p_ptt, p_vf, length, status);
}