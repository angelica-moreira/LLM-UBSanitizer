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
typedef  int uint64_t ;
struct TYPE_9__ {scalar_t__ gpu_addr; int /*<<< orphan*/ * wb; scalar_t__ use_event; } ;
struct TYPE_8__ {int reg_base; } ;
struct TYPE_7__ {scalar_t__ gpu_addr; int /*<<< orphan*/ * cpu_addr; } ;
struct radeon_device {TYPE_5__* fence_drv; int /*<<< orphan*/  dev; TYPE_4__ wb; TYPE_3__ scratch; TYPE_2__ uvd; TYPE_1__* uvd_fw; int /*<<< orphan*/ * ring; } ;
struct TYPE_10__ {int scratch_reg; int initialized; int /*<<< orphan*/ * cpu_addr; scalar_t__ gpu_addr; int /*<<< orphan*/  last_seq; } ;
struct TYPE_6__ {int /*<<< orphan*/  size; } ;

/* Variables and functions */
 int ALIGN (int /*<<< orphan*/ ,int) ; 
 int R600_RING_TYPE_UVD_INDEX ; 
 int R600_WB_EVENT_OFFSET ; 
 int RADEON_WB_SCRATCH_OFFSET ; 
 int /*<<< orphan*/  atomic64_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  radeon_fence_write (struct radeon_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  radeon_ring_supports_scratch_reg (struct radeon_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  radeon_scratch_free (struct radeon_device*,int) ; 
 int radeon_scratch_get (struct radeon_device*,int*) ; 

int radeon_fence_driver_start_ring(struct radeon_device *rdev, int ring)
{
	uint64_t index;
	int r;

	radeon_scratch_free(rdev, rdev->fence_drv[ring].scratch_reg);
	if (rdev->wb.use_event || !radeon_ring_supports_scratch_reg(rdev, &rdev->ring[ring])) {
		rdev->fence_drv[ring].scratch_reg = 0;
		if (ring != R600_RING_TYPE_UVD_INDEX) {
			index = R600_WB_EVENT_OFFSET + ring * 4;
			rdev->fence_drv[ring].cpu_addr = &rdev->wb.wb[index/4];
			rdev->fence_drv[ring].gpu_addr = rdev->wb.gpu_addr +
							 index;

		} else {
			/* put fence directly behind firmware */
			index = ALIGN(rdev->uvd_fw->size, 8);
			rdev->fence_drv[ring].cpu_addr = rdev->uvd.cpu_addr + index;
			rdev->fence_drv[ring].gpu_addr = rdev->uvd.gpu_addr + index;
		}

	} else {
		r = radeon_scratch_get(rdev, &rdev->fence_drv[ring].scratch_reg);
		if (r) {
			dev_err(rdev->dev, "fence failed to get scratch register\n");
			return r;
		}
		index = RADEON_WB_SCRATCH_OFFSET +
			rdev->fence_drv[ring].scratch_reg -
			rdev->scratch.reg_base;
		rdev->fence_drv[ring].cpu_addr = &rdev->wb.wb[index/4];
		rdev->fence_drv[ring].gpu_addr = rdev->wb.gpu_addr + index;
	}
	radeon_fence_write(rdev, atomic64_read(&rdev->fence_drv[ring].last_seq), ring);
	rdev->fence_drv[ring].initialized = true;
	dev_info(rdev->dev, "fence driver on ring %d use gpu addr 0x%016llx and cpu addr 0x%p\n",
		 ring, rdev->fence_drv[ring].gpu_addr, rdev->fence_drv[ring].cpu_addr);
	return 0;
}