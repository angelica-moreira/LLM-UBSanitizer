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
struct rvt_cq {int notify; int /*<<< orphan*/  lock; TYPE_2__* kqueue; TYPE_1__* queue; } ;
struct ib_cq {int dummy; } ;
typedef  enum ib_cq_notify_flags { ____Placeholder_ib_cq_notify_flags } ib_cq_notify_flags ;
struct TYPE_4__ {scalar_t__ head; scalar_t__ tail; } ;
struct TYPE_3__ {int /*<<< orphan*/  tail; int /*<<< orphan*/  head; } ;

/* Variables and functions */
 int IB_CQ_NEXT_COMP ; 
 int IB_CQ_REPORT_MISSED_EVENTS ; 
 int IB_CQ_SOLICITED_MASK ; 
 scalar_t__ RDMA_READ_UAPI_ATOMIC (int /*<<< orphan*/ ) ; 
 struct rvt_cq* ibcq_to_rvtcq (struct ib_cq*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int rvt_req_notify_cq(struct ib_cq *ibcq, enum ib_cq_notify_flags notify_flags)
{
	struct rvt_cq *cq = ibcq_to_rvtcq(ibcq);
	unsigned long flags;
	int ret = 0;

	spin_lock_irqsave(&cq->lock, flags);
	/*
	 * Don't change IB_CQ_NEXT_COMP to IB_CQ_SOLICITED but allow
	 * any other transitions (see C11-31 and C11-32 in ch. 11.4.2.2).
	 */
	if (cq->notify != IB_CQ_NEXT_COMP)
		cq->notify = notify_flags & IB_CQ_SOLICITED_MASK;

	if (notify_flags & IB_CQ_REPORT_MISSED_EVENTS) {
		if (cq->queue) {
			if (RDMA_READ_UAPI_ATOMIC(cq->queue->head) !=
				RDMA_READ_UAPI_ATOMIC(cq->queue->tail))
				ret = 1;
		} else {
			if (cq->kqueue->head != cq->kqueue->tail)
				ret = 1;
		}
	}

	spin_unlock_irqrestore(&cq->lock, flags);

	return ret;
}