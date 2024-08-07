#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  int u32 ;
struct qed_ptt {int dummy; } ;
struct TYPE_6__ {int val; } ;
struct qed_ilt_client_cfg {TYPE_1__ p_size; struct qed_ilt_cli_blk* pf_blks; } ;
struct qed_ilt_cli_blk {int start_line; } ;
struct qed_hwfn {TYPE_5__* p_cxt_mngr; TYPE_3__* cdev; } ;
typedef  int /*<<< orphan*/  ilt_hw_entry ;
typedef  enum qed_cxt_elem_type { ____Placeholder_qed_cxt_elem_type } qed_cxt_elem_type ;
struct TYPE_10__ {int pf_start_line; TYPE_4__* ilt_shadow; struct qed_ilt_client_cfg* clients; } ;
struct TYPE_9__ {scalar_t__ size; scalar_t__ p_phys; int /*<<< orphan*/ * p_virt; } ;
struct TYPE_8__ {TYPE_2__* pdev; } ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 size_t CDUC_BLK ; 
 size_t CDUT_SEG_BLK (int /*<<< orphan*/ ) ; 
 int CONN_CXT_SIZE (struct qed_hwfn*) ; 
 int /*<<< orphan*/  DP_NOTICE (struct qed_hwfn*,char*,...) ; 
 int EBUSY ; 
 int EINVAL ; 
 size_t ILT_CLI_CDUC ; 
 size_t ILT_CLI_CDUT ; 
 size_t ILT_CLI_TSDM ; 
 int ILT_ENTRY_IN_REGS ; 
 int ILT_PAGE_IN_BYTES (int) ; 
 int ILT_REG_SIZE_IN_BYTES ; 
 int PSWRQ2_REG_ILT_MEMORY ; 
 int /*<<< orphan*/  QED_CXT_ROCE_TID_SEG ; 
#define  QED_ELEM_CXT 130 
#define  QED_ELEM_SRQ 129 
#define  QED_ELEM_TASK 128 
 size_t SRQ_BLK ; 
 int SRQ_CXT_SIZE ; 
 int TYPE1_TASK_CXT_SIZE (struct qed_hwfn*) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  qed_dmae_host2grc (struct qed_hwfn*,struct qed_ptt*,scalar_t__,int,int,int /*<<< orphan*/ *) ; 
 struct qed_ptt* qed_ptt_acquire (struct qed_hwfn*) ; 
 int /*<<< orphan*/  qed_ptt_release (struct qed_hwfn*,struct qed_ptt*) ; 

__attribute__((used)) static int
qed_cxt_free_ilt_range(struct qed_hwfn *p_hwfn,
		       enum qed_cxt_elem_type elem_type,
		       u32 start_iid, u32 count)
{
	u32 start_line, end_line, shadow_start_line, shadow_end_line;
	u32 reg_offset, elem_size, hw_p_size, elems_per_p;
	struct qed_ilt_client_cfg *p_cli;
	struct qed_ilt_cli_blk *p_blk;
	u32 end_iid = start_iid + count;
	struct qed_ptt *p_ptt;
	u64 ilt_hw_entry = 0;
	u32 i;

	switch (elem_type) {
	case QED_ELEM_CXT:
		p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUC];
		elem_size = CONN_CXT_SIZE(p_hwfn);
		p_blk = &p_cli->pf_blks[CDUC_BLK];
		break;
	case QED_ELEM_SRQ:
		p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_TSDM];
		elem_size = SRQ_CXT_SIZE;
		p_blk = &p_cli->pf_blks[SRQ_BLK];
		break;
	case QED_ELEM_TASK:
		p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUT];
		elem_size = TYPE1_TASK_CXT_SIZE(p_hwfn);
		p_blk = &p_cli->pf_blks[CDUT_SEG_BLK(QED_CXT_ROCE_TID_SEG)];
		break;
	default:
		DP_NOTICE(p_hwfn, "-EINVALID elem type = %d", elem_type);
		return -EINVAL;
	}

	/* Calculate line in ilt */
	hw_p_size = p_cli->p_size.val;
	elems_per_p = ILT_PAGE_IN_BYTES(hw_p_size) / elem_size;
	start_line = p_blk->start_line + (start_iid / elems_per_p);
	end_line = p_blk->start_line + (end_iid / elems_per_p);
	if (((end_iid + 1) / elems_per_p) != (end_iid / elems_per_p))
		end_line--;

	shadow_start_line = start_line - p_hwfn->p_cxt_mngr->pf_start_line;
	shadow_end_line = end_line - p_hwfn->p_cxt_mngr->pf_start_line;

	p_ptt = qed_ptt_acquire(p_hwfn);
	if (!p_ptt) {
		DP_NOTICE(p_hwfn,
			  "QED_TIME_OUT on ptt acquire - dynamic allocation");
		return -EBUSY;
	}

	for (i = shadow_start_line; i < shadow_end_line; i++) {
		if (!p_hwfn->p_cxt_mngr->ilt_shadow[i].p_virt)
			continue;

		dma_free_coherent(&p_hwfn->cdev->pdev->dev,
				  p_hwfn->p_cxt_mngr->ilt_shadow[i].size,
				  p_hwfn->p_cxt_mngr->ilt_shadow[i].p_virt,
				  p_hwfn->p_cxt_mngr->ilt_shadow[i].p_phys);

		p_hwfn->p_cxt_mngr->ilt_shadow[i].p_virt = NULL;
		p_hwfn->p_cxt_mngr->ilt_shadow[i].p_phys = 0;
		p_hwfn->p_cxt_mngr->ilt_shadow[i].size = 0;

		/* compute absolute offset */
		reg_offset = PSWRQ2_REG_ILT_MEMORY +
		    ((start_line++) * ILT_REG_SIZE_IN_BYTES *
		     ILT_ENTRY_IN_REGS);

		/* Write via DMAE since the PSWRQ2_REG_ILT_MEMORY line is a
		 * wide-bus.
		 */
		qed_dmae_host2grc(p_hwfn, p_ptt,
				  (u64) (uintptr_t) &ilt_hw_entry,
				  reg_offset,
				  sizeof(ilt_hw_entry) / sizeof(u32),
				  NULL);
	}

	qed_ptt_release(p_hwfn, p_ptt);

	return 0;
}