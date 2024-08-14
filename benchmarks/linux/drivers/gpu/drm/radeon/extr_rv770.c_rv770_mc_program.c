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
typedef  int u32 ;
struct rv515_mc_save {int dummy; } ;
struct TYPE_4__ {int vram_start; int gtt_start; int gtt_end; int vram_end; int agp_base; } ;
struct TYPE_3__ {int gpu_addr; } ;
struct radeon_device {int flags; int /*<<< orphan*/  dev; TYPE_2__ mc; TYPE_1__ vram_scratch; } ;

/* Variables and functions */
 int /*<<< orphan*/  HDP_DEBUG1 ; 
 int HDP_NONSURFACE_BASE ; 
 int HDP_NONSURFACE_INFO ; 
 int HDP_NONSURFACE_SIZE ; 
 int MC_VM_AGP_BASE ; 
 int MC_VM_AGP_BOT ; 
 int MC_VM_AGP_TOP ; 
 int MC_VM_FB_LOCATION ; 
 int MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR ; 
 int MC_VM_SYSTEM_APERTURE_HIGH_ADDR ; 
 int MC_VM_SYSTEM_APERTURE_LOW_ADDR ; 
 int RADEON_IS_AGP ; 
 int RREG32 (int /*<<< orphan*/ ) ; 
 int VGA_HDP_CONTROL ; 
 int VGA_MEMORY_DISABLE ; 
 int /*<<< orphan*/  WREG32 (int,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ r600_mc_wait_for_idle (struct radeon_device*) ; 
 int /*<<< orphan*/  rv515_mc_resume (struct radeon_device*,struct rv515_mc_save*) ; 
 int /*<<< orphan*/  rv515_mc_stop (struct radeon_device*,struct rv515_mc_save*) ; 
 int /*<<< orphan*/  rv515_vga_render_disable (struct radeon_device*) ; 

__attribute__((used)) static void rv770_mc_program(struct radeon_device *rdev)
{
	struct rv515_mc_save save;
	u32 tmp;
	int i, j;

	/* Initialize HDP */
	for (i = 0, j = 0; i < 32; i++, j += 0x18) {
		WREG32((0x2c14 + j), 0x00000000);
		WREG32((0x2c18 + j), 0x00000000);
		WREG32((0x2c1c + j), 0x00000000);
		WREG32((0x2c20 + j), 0x00000000);
		WREG32((0x2c24 + j), 0x00000000);
	}
	/* r7xx hw bug.  Read from HDP_DEBUG1 rather
	 * than writing to HDP_REG_COHERENCY_FLUSH_CNTL
	 */
	tmp = RREG32(HDP_DEBUG1);

	rv515_mc_stop(rdev, &save);
	if (r600_mc_wait_for_idle(rdev)) {
		dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
	}
	/* Lockout access through VGA aperture*/
	WREG32(VGA_HDP_CONTROL, VGA_MEMORY_DISABLE);
	/* Update configuration */
	if (rdev->flags & RADEON_IS_AGP) {
		if (rdev->mc.vram_start < rdev->mc.gtt_start) {
			/* VRAM before AGP */
			WREG32(MC_VM_SYSTEM_APERTURE_LOW_ADDR,
				rdev->mc.vram_start >> 12);
			WREG32(MC_VM_SYSTEM_APERTURE_HIGH_ADDR,
				rdev->mc.gtt_end >> 12);
		} else {
			/* VRAM after AGP */
			WREG32(MC_VM_SYSTEM_APERTURE_LOW_ADDR,
				rdev->mc.gtt_start >> 12);
			WREG32(MC_VM_SYSTEM_APERTURE_HIGH_ADDR,
				rdev->mc.vram_end >> 12);
		}
	} else {
		WREG32(MC_VM_SYSTEM_APERTURE_LOW_ADDR,
			rdev->mc.vram_start >> 12);
		WREG32(MC_VM_SYSTEM_APERTURE_HIGH_ADDR,
			rdev->mc.vram_end >> 12);
	}
	WREG32(MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR, rdev->vram_scratch.gpu_addr >> 12);
	tmp = ((rdev->mc.vram_end >> 24) & 0xFFFF) << 16;
	tmp |= ((rdev->mc.vram_start >> 24) & 0xFFFF);
	WREG32(MC_VM_FB_LOCATION, tmp);
	WREG32(HDP_NONSURFACE_BASE, (rdev->mc.vram_start >> 8));
	WREG32(HDP_NONSURFACE_INFO, (2 << 7));
	WREG32(HDP_NONSURFACE_SIZE, 0x3FFFFFFF);
	if (rdev->flags & RADEON_IS_AGP) {
		WREG32(MC_VM_AGP_TOP, rdev->mc.gtt_end >> 16);
		WREG32(MC_VM_AGP_BOT, rdev->mc.gtt_start >> 16);
		WREG32(MC_VM_AGP_BASE, rdev->mc.agp_base >> 22);
	} else {
		WREG32(MC_VM_AGP_BASE, 0);
		WREG32(MC_VM_AGP_TOP, 0x0FFFFFFF);
		WREG32(MC_VM_AGP_BOT, 0x0FFFFFFF);
	}
	if (r600_mc_wait_for_idle(rdev)) {
		dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
	}
	rv515_mc_resume(rdev, &save);
	/* we need to own VRAM, so turn off the VGA renderer here
	 * to stop it overwriting our objects */
	rv515_vga_render_disable(rdev);
}