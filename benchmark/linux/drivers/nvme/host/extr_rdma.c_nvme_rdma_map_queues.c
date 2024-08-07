#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct nvmf_ctrl_options {scalar_t__ nr_poll_queues; scalar_t__ nr_write_queues; } ;
struct TYPE_6__ {int /*<<< orphan*/  device; struct nvmf_ctrl_options* opts; } ;
struct nvme_rdma_ctrl {scalar_t__* io_queues; TYPE_2__ ctrl; TYPE_1__* device; } ;
struct blk_mq_tag_set {TYPE_3__* map; struct nvme_rdma_ctrl* driver_data; } ;
struct TYPE_7__ {scalar_t__ queue_offset; scalar_t__ nr_queues; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 size_t HCTX_TYPE_DEFAULT ; 
 size_t HCTX_TYPE_POLL ; 
 size_t HCTX_TYPE_READ ; 
 int /*<<< orphan*/  blk_mq_map_queues (TYPE_3__*) ; 
 int /*<<< orphan*/  blk_mq_rdma_map_queues (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,scalar_t__,scalar_t__,scalar_t__) ; 

__attribute__((used)) static int nvme_rdma_map_queues(struct blk_mq_tag_set *set)
{
	struct nvme_rdma_ctrl *ctrl = set->driver_data;
	struct nvmf_ctrl_options *opts = ctrl->ctrl.opts;

	if (opts->nr_write_queues && ctrl->io_queues[HCTX_TYPE_READ]) {
		/* separate read/write queues */
		set->map[HCTX_TYPE_DEFAULT].nr_queues =
			ctrl->io_queues[HCTX_TYPE_DEFAULT];
		set->map[HCTX_TYPE_DEFAULT].queue_offset = 0;
		set->map[HCTX_TYPE_READ].nr_queues =
			ctrl->io_queues[HCTX_TYPE_READ];
		set->map[HCTX_TYPE_READ].queue_offset =
			ctrl->io_queues[HCTX_TYPE_DEFAULT];
	} else {
		/* shared read/write queues */
		set->map[HCTX_TYPE_DEFAULT].nr_queues =
			ctrl->io_queues[HCTX_TYPE_DEFAULT];
		set->map[HCTX_TYPE_DEFAULT].queue_offset = 0;
		set->map[HCTX_TYPE_READ].nr_queues =
			ctrl->io_queues[HCTX_TYPE_DEFAULT];
		set->map[HCTX_TYPE_READ].queue_offset = 0;
	}
	blk_mq_rdma_map_queues(&set->map[HCTX_TYPE_DEFAULT],
			ctrl->device->dev, 0);
	blk_mq_rdma_map_queues(&set->map[HCTX_TYPE_READ],
			ctrl->device->dev, 0);

	if (opts->nr_poll_queues && ctrl->io_queues[HCTX_TYPE_POLL]) {
		/* map dedicated poll queues only if we have queues left */
		set->map[HCTX_TYPE_POLL].nr_queues =
				ctrl->io_queues[HCTX_TYPE_POLL];
		set->map[HCTX_TYPE_POLL].queue_offset =
			ctrl->io_queues[HCTX_TYPE_DEFAULT] +
			ctrl->io_queues[HCTX_TYPE_READ];
		blk_mq_map_queues(&set->map[HCTX_TYPE_POLL]);
	}

	dev_info(ctrl->ctrl.device,
		"mapped %d/%d/%d default/read/poll queues.\n",
		ctrl->io_queues[HCTX_TYPE_DEFAULT],
		ctrl->io_queues[HCTX_TYPE_READ],
		ctrl->io_queues[HCTX_TYPE_POLL]);

	return 0;
}