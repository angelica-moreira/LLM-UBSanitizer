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
struct TYPE_4__ {TYPE_1__* cqe; scalar_t__ transfer_len; int /*<<< orphan*/  cmd; } ;
struct nvmet_rdma_rsp {int flags; TYPE_2__ req; } ;
struct TYPE_3__ {int /*<<< orphan*/  status; } ;

/* Variables and functions */
 int NVMET_RDMA_REQ_INLINE_DATA ; 
 int /*<<< orphan*/  nvme_is_write (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool nvmet_rdma_need_data_out(struct nvmet_rdma_rsp *rsp)
{
	return !nvme_is_write(rsp->req.cmd) &&
		rsp->req.transfer_len &&
		!rsp->req.cqe->status &&
		!(rsp->flags & NVMET_RDMA_REQ_INLINE_DATA);
}