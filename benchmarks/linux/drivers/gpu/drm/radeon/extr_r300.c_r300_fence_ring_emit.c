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
struct radeon_ring {int dummy; } ;
struct radeon_fence {size_t ring; int seq; } ;
struct TYPE_4__ {int hdp_cntl; } ;
struct TYPE_5__ {TYPE_1__ r300; } ;
struct radeon_device {TYPE_3__* fence_drv; TYPE_2__ config; struct radeon_ring* ring; } ;
struct TYPE_6__ {int /*<<< orphan*/  scratch_reg; } ;

/* Variables and functions */
 int PACKET0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int R300_RB3D_DC_FLUSH ; 
 int /*<<< orphan*/  R300_RB3D_DSTCACHE_CTLSTAT ; 
 int /*<<< orphan*/  R300_RB3D_ZCACHE_CTLSTAT ; 
 int /*<<< orphan*/  R300_RE_SCISSORS_BR ; 
 int /*<<< orphan*/  R300_RE_SCISSORS_TL ; 
 int R300_ZC_FLUSH ; 
 int /*<<< orphan*/  RADEON_GEN_INT_STATUS ; 
 int RADEON_HDP_READ_BUFFER_INVALIDATE ; 
 int /*<<< orphan*/  RADEON_HOST_PATH_CNTL ; 
 int RADEON_SW_INT_FIRE ; 
 int RADEON_WAIT_2D_IDLECLEAN ; 
 int RADEON_WAIT_3D_IDLECLEAN ; 
 int RADEON_WAIT_DMA_GUI_IDLE ; 
 int /*<<< orphan*/  RADEON_WAIT_UNTIL ; 
 int /*<<< orphan*/  radeon_ring_write (struct radeon_ring*,int) ; 

void r300_fence_ring_emit(struct radeon_device *rdev,
			  struct radeon_fence *fence)
{
	struct radeon_ring *ring = &rdev->ring[fence->ring];

	/* Who ever call radeon_fence_emit should call ring_lock and ask
	 * for enough space (today caller are ib schedule and buffer move) */
	/* Write SC register so SC & US assert idle */
	radeon_ring_write(ring, PACKET0(R300_RE_SCISSORS_TL, 0));
	radeon_ring_write(ring, 0);
	radeon_ring_write(ring, PACKET0(R300_RE_SCISSORS_BR, 0));
	radeon_ring_write(ring, 0);
	/* Flush 3D cache */
	radeon_ring_write(ring, PACKET0(R300_RB3D_DSTCACHE_CTLSTAT, 0));
	radeon_ring_write(ring, R300_RB3D_DC_FLUSH);
	radeon_ring_write(ring, PACKET0(R300_RB3D_ZCACHE_CTLSTAT, 0));
	radeon_ring_write(ring, R300_ZC_FLUSH);
	/* Wait until IDLE & CLEAN */
	radeon_ring_write(ring, PACKET0(RADEON_WAIT_UNTIL, 0));
	radeon_ring_write(ring, (RADEON_WAIT_3D_IDLECLEAN |
				 RADEON_WAIT_2D_IDLECLEAN |
				 RADEON_WAIT_DMA_GUI_IDLE));
	radeon_ring_write(ring, PACKET0(RADEON_HOST_PATH_CNTL, 0));
	radeon_ring_write(ring, rdev->config.r300.hdp_cntl |
				RADEON_HDP_READ_BUFFER_INVALIDATE);
	radeon_ring_write(ring, PACKET0(RADEON_HOST_PATH_CNTL, 0));
	radeon_ring_write(ring, rdev->config.r300.hdp_cntl);
	/* Emit fence sequence & fire IRQ */
	radeon_ring_write(ring, PACKET0(rdev->fence_drv[fence->ring].scratch_reg, 0));
	radeon_ring_write(ring, fence->seq);
	radeon_ring_write(ring, PACKET0(RADEON_GEN_INT_STATUS, 0));
	radeon_ring_write(ring, RADEON_SW_INT_FIRE);
}