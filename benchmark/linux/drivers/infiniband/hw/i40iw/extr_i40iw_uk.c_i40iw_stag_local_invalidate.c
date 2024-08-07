#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct i40iw_qp_uk {int swqe_polarity; } ;
struct i40iw_inv_local_stag {int target_stag; } ;
struct TYPE_2__ {struct i40iw_inv_local_stag inv_local_stag; } ;
struct i40iw_post_sq_info {int local_fence; int read_fence; int signaled; int /*<<< orphan*/  wr_id; TYPE_1__ op; } ;
typedef  enum i40iw_status_code { ____Placeholder_i40iw_status_code } i40iw_status_code ;

/* Variables and functions */
 int /*<<< orphan*/  I40IWQPSQ_LOCALFENCE ; 
 int /*<<< orphan*/  I40IWQPSQ_LOCSTAG ; 
 int /*<<< orphan*/  I40IWQPSQ_OPCODE ; 
 int /*<<< orphan*/  I40IWQPSQ_READFENCE ; 
 int /*<<< orphan*/  I40IWQPSQ_SIGCOMPL ; 
 int /*<<< orphan*/  I40IWQPSQ_VALID ; 
 int I40IW_ERR_QP_TOOMANY_WRS_POSTED ; 
 int I40IW_OP_TYPE_INV_STAG ; 
 int /*<<< orphan*/  I40IW_QP_WQE_MIN_SIZE ; 
 int LS_64 (int,int /*<<< orphan*/ ) ; 
 int* i40iw_qp_get_next_send_wqe (struct i40iw_qp_uk*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i40iw_qp_post_wr (struct i40iw_qp_uk*) ; 
 int /*<<< orphan*/  set_64bit_val (int*,int,int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static enum i40iw_status_code i40iw_stag_local_invalidate(struct i40iw_qp_uk *qp,
							  struct i40iw_post_sq_info *info,
							  bool post_sq)
{
	u64 *wqe;
	struct i40iw_inv_local_stag *op_info;
	u64 header;
	u32 wqe_idx;
	bool local_fence = false;

	op_info = &info->op.inv_local_stag;
	local_fence = info->local_fence;

	wqe = i40iw_qp_get_next_send_wqe(qp, &wqe_idx, I40IW_QP_WQE_MIN_SIZE, 0, info->wr_id);
	if (!wqe)
		return I40IW_ERR_QP_TOOMANY_WRS_POSTED;
	set_64bit_val(wqe, 0, 0);
	set_64bit_val(wqe, 8,
		      LS_64(op_info->target_stag, I40IWQPSQ_LOCSTAG));
	set_64bit_val(wqe, 16, 0);
	header = LS_64(I40IW_OP_TYPE_INV_STAG, I40IWQPSQ_OPCODE) |
	    LS_64(info->read_fence, I40IWQPSQ_READFENCE) |
	    LS_64(local_fence, I40IWQPSQ_LOCALFENCE) |
	    LS_64(info->signaled, I40IWQPSQ_SIGCOMPL) |
	    LS_64(qp->swqe_polarity, I40IWQPSQ_VALID);

	wmb(); /* make sure WQE is populated before valid bit is set */

	set_64bit_val(wqe, 24, header);

	if (post_sq)
		i40iw_qp_post_wr(qp);

	return 0;
}