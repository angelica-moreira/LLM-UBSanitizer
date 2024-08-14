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
struct TYPE_6__ {int max_wqe_idx; } ;
struct ocrdma_srq {TYPE_3__ rq; int /*<<< orphan*/  q_lock; int /*<<< orphan*/ * rqe_wr_id_tbl; } ;
struct TYPE_5__ {int /*<<< orphan*/  srq; } ;
struct ocrdma_qp {TYPE_2__ ibqp; } ;
struct TYPE_4__ {int /*<<< orphan*/  buftag_qpn; } ;
struct ocrdma_cqe {TYPE_1__ rq; } ;
struct ib_wc {int /*<<< orphan*/  wr_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int OCRDMA_CQE_BUFTAG_SHIFT ; 
 struct ocrdma_srq* get_ocrdma_srq (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocrdma_hwq_inc_tail (TYPE_3__*) ; 
 int /*<<< orphan*/  ocrdma_srq_toggle_bit (struct ocrdma_srq*,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void ocrdma_update_free_srq_cqe(struct ib_wc *ibwc,
				       struct ocrdma_cqe *cqe,
				       struct ocrdma_qp *qp)
{
	unsigned long flags;
	struct ocrdma_srq *srq;
	u32 wqe_idx;

	srq = get_ocrdma_srq(qp->ibqp.srq);
	wqe_idx = (le32_to_cpu(cqe->rq.buftag_qpn) >>
		OCRDMA_CQE_BUFTAG_SHIFT) & srq->rq.max_wqe_idx;
	BUG_ON(wqe_idx < 1);

	ibwc->wr_id = srq->rqe_wr_id_tbl[wqe_idx];
	spin_lock_irqsave(&srq->q_lock, flags);
	ocrdma_srq_toggle_bit(srq, wqe_idx - 1);
	spin_unlock_irqrestore(&srq->q_lock, flags);
	ocrdma_hwq_inc_tail(&srq->rq);
}