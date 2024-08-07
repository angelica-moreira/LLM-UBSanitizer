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
typedef  int /*<<< orphan*/  u8 ;
typedef  size_t u32 ;
struct siw_rqe {int /*<<< orphan*/  flags; int /*<<< orphan*/  id; } ;
struct siw_qp {int /*<<< orphan*/  ib_qp; struct siw_cq* rcq; } ;
struct siw_cqe {int status; size_t bytes; size_t inval_stag; int /*<<< orphan*/  flags; int /*<<< orphan*/  qp_id; int /*<<< orphan*/  base_qp; scalar_t__ imm_data; int /*<<< orphan*/  opcode; int /*<<< orphan*/  id; } ;
struct TYPE_2__ {int /*<<< orphan*/  cq_context; int /*<<< orphan*/  (* comp_handler ) (TYPE_1__*,int /*<<< orphan*/ ) ;} ;
struct siw_cq {size_t cq_put; size_t num_cqe; int /*<<< orphan*/  lock; TYPE_1__ base_cq; scalar_t__ kernel_verbs; struct siw_cqe* queue; } ;
typedef  enum siw_wc_status { ____Placeholder_siw_wc_status } siw_wc_status ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  IB_EVENT_CQ_ERR ; 
 int /*<<< orphan*/  READ_ONCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SIW_OP_RECEIVE ; 
 int /*<<< orphan*/  SIW_WQE_REM_INVAL ; 
 int /*<<< orphan*/  SIW_WQE_SIGNALLED ; 
 int /*<<< orphan*/  SIW_WQE_VALID ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qp_id (struct siw_qp*) ; 
 int /*<<< orphan*/  siw_cq_event (struct siw_cq*,int /*<<< orphan*/ ) ; 
 int siw_cq_notify_now (struct siw_cq*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  siw_dbg_cq (struct siw_cq*,char*) ; 
 int /*<<< orphan*/  smp_store_mb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ ) ; 

int siw_rqe_complete(struct siw_qp *qp, struct siw_rqe *rqe, u32 bytes,
		     u32 inval_stag, enum siw_wc_status status)
{
	struct siw_cq *cq = qp->rcq;
	int rv = 0;

	if (cq) {
		struct siw_cqe *cqe;
		u32 idx;
		unsigned long flags;

		spin_lock_irqsave(&cq->lock, flags);

		idx = cq->cq_put % cq->num_cqe;
		cqe = &cq->queue[idx];

		if (!READ_ONCE(cqe->flags)) {
			bool notify;
			u8 cqe_flags = SIW_WQE_VALID;

			cqe->id = rqe->id;
			cqe->opcode = SIW_OP_RECEIVE;
			cqe->status = status;
			cqe->imm_data = 0;
			cqe->bytes = bytes;

			if (cq->kernel_verbs) {
				cqe->base_qp = qp->ib_qp;
				if (inval_stag) {
					cqe_flags |= SIW_WQE_REM_INVAL;
					cqe->inval_stag = inval_stag;
				}
			} else {
				cqe->qp_id = qp_id(qp);
			}
			/* mark CQE valid for application */
			WRITE_ONCE(cqe->flags, cqe_flags);
			/* recycle RQE */
			smp_store_mb(rqe->flags, 0);

			cq->cq_put++;
			notify = siw_cq_notify_now(cq, SIW_WQE_SIGNALLED);

			spin_unlock_irqrestore(&cq->lock, flags);

			if (notify) {
				siw_dbg_cq(cq, "Call completion handler\n");
				cq->base_cq.comp_handler(&cq->base_cq,
						cq->base_cq.cq_context);
			}
		} else {
			spin_unlock_irqrestore(&cq->lock, flags);
			rv = -ENOMEM;
			siw_cq_event(cq, IB_EVENT_CQ_ERR);
		}
	} else {
		/* recycle RQE */
		smp_store_mb(rqe->flags, 0);
	}
	return rv;
}