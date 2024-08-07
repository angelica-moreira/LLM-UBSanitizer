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
struct TYPE_2__ {int queue_count; } ;
struct nvme_rdma_ctrl {int /*<<< orphan*/ * queues; TYPE_1__ ctrl; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvme_rdma_free_queue (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void nvme_rdma_free_io_queues(struct nvme_rdma_ctrl *ctrl)
{
	int i;

	for (i = 1; i < ctrl->ctrl.queue_count; i++)
		nvme_rdma_free_queue(&ctrl->queues[i]);
}