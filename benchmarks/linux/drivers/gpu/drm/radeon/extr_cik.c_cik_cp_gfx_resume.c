#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct radeon_ring {int ring_size; int wptr; int gpu_addr; int ready; } ;
struct TYPE_8__ {int /*<<< orphan*/  real_vram_size; } ;
struct TYPE_5__ {int gpu_addr; int /*<<< orphan*/  enabled; } ;
struct radeon_device {scalar_t__ family; TYPE_4__ mc; TYPE_3__* asic; struct radeon_ring* ring; TYPE_1__ wb; } ;
struct TYPE_6__ {size_t copy_ring_index; } ;
struct TYPE_7__ {TYPE_2__ copy; } ;

/* Variables and functions */
 int BUF_SWAP_32BIT ; 
 scalar_t__ CHIP_HAWAII ; 
 int /*<<< orphan*/  CP_RB0_BASE ; 
 int /*<<< orphan*/  CP_RB0_BASE_HI ; 
 int /*<<< orphan*/  CP_RB0_CNTL ; 
 int /*<<< orphan*/  CP_RB0_RPTR_ADDR ; 
 int /*<<< orphan*/  CP_RB0_RPTR_ADDR_HI ; 
 int /*<<< orphan*/  CP_RB0_WPTR ; 
 int /*<<< orphan*/  CP_RB_VMID ; 
 int /*<<< orphan*/  CP_RB_WPTR_DELAY ; 
 int /*<<< orphan*/  CP_SEM_INCOMPLETE_TIMER_CNTL ; 
 int /*<<< orphan*/  CP_SEM_WAIT_TIMER ; 
 int RADEON_GPU_PAGE_SIZE ; 
 size_t RADEON_RING_TYPE_GFX_INDEX ; 
 int RADEON_WB_CP_RPTR_OFFSET ; 
 int RADEON_WB_SCRATCH_OFFSET ; 
 int RB_NO_UPDATE ; 
 int RB_RPTR_WR_ENA ; 
 int /*<<< orphan*/  SCRATCH_ADDR ; 
 int /*<<< orphan*/  SCRATCH_UMSK ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cik_cp_gfx_start (struct radeon_device*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int order_base_2 (int) ; 
 int radeon_ring_test (struct radeon_device*,size_t,struct radeon_ring*) ; 
 int /*<<< orphan*/  radeon_ttm_set_active_vram_size (struct radeon_device*,int /*<<< orphan*/ ) ; 
 int upper_32_bits (int) ; 

__attribute__((used)) static int cik_cp_gfx_resume(struct radeon_device *rdev)
{
	struct radeon_ring *ring;
	u32 tmp;
	u32 rb_bufsz;
	u64 rb_addr;
	int r;

	WREG32(CP_SEM_WAIT_TIMER, 0x0);
	if (rdev->family != CHIP_HAWAII)
		WREG32(CP_SEM_INCOMPLETE_TIMER_CNTL, 0x0);

	/* Set the write pointer delay */
	WREG32(CP_RB_WPTR_DELAY, 0);

	/* set the RB to use vmid 0 */
	WREG32(CP_RB_VMID, 0);

	WREG32(SCRATCH_ADDR, ((rdev->wb.gpu_addr + RADEON_WB_SCRATCH_OFFSET) >> 8) & 0xFFFFFFFF);

	/* ring 0 - compute and gfx */
	/* Set ring buffer size */
	ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
	rb_bufsz = order_base_2(ring->ring_size / 8);
	tmp = (order_base_2(RADEON_GPU_PAGE_SIZE/8) << 8) | rb_bufsz;
#ifdef __BIG_ENDIAN
	tmp |= BUF_SWAP_32BIT;
#endif
	WREG32(CP_RB0_CNTL, tmp);

	/* Initialize the ring buffer's read and write pointers */
	WREG32(CP_RB0_CNTL, tmp | RB_RPTR_WR_ENA);
	ring->wptr = 0;
	WREG32(CP_RB0_WPTR, ring->wptr);

	/* set the wb address wether it's enabled or not */
	WREG32(CP_RB0_RPTR_ADDR, (rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFFFFFFFC);
	WREG32(CP_RB0_RPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFF);

	/* scratch register shadowing is no longer supported */
	WREG32(SCRATCH_UMSK, 0);

	if (!rdev->wb.enabled)
		tmp |= RB_NO_UPDATE;

	mdelay(1);
	WREG32(CP_RB0_CNTL, tmp);

	rb_addr = ring->gpu_addr >> 8;
	WREG32(CP_RB0_BASE, rb_addr);
	WREG32(CP_RB0_BASE_HI, upper_32_bits(rb_addr));

	/* start the ring */
	cik_cp_gfx_start(rdev);
	rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = true;
	r = radeon_ring_test(rdev, RADEON_RING_TYPE_GFX_INDEX, &rdev->ring[RADEON_RING_TYPE_GFX_INDEX]);
	if (r) {
		rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = false;
		return r;
	}

	if (rdev->asic->copy.copy_ring_index == RADEON_RING_TYPE_GFX_INDEX)
		radeon_ttm_set_active_vram_size(rdev, rdev->mc.real_vram_size);

	return 0;
}