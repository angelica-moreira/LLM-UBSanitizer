#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct radeon_encoder {int devices; } ;
struct radeon_device {int dummy; } ;
struct drm_encoder {struct drm_device* dev; } ;
struct drm_device {struct radeon_device* dev_private; } ;

/* Variables and functions */
 int ATOM_DEVICE_CRT_SUPPORT ; 
 int ATOM_DEVICE_DFP_SUPPORT ; 
 int ATOM_DEVICE_LCD_SUPPORT ; 
 int ATOM_DEVICE_TV_SUPPORT ; 
 int /*<<< orphan*/  RADEON_BIOS_6_SCRATCH ; 
 int /*<<< orphan*/  RADEON_CRT_DPMS_ON ; 
 int /*<<< orphan*/  RADEON_DFP_DPMS_ON ; 
 int /*<<< orphan*/  RADEON_LCD_DPMS_ON ; 
 int /*<<< orphan*/  RADEON_TV_DPMS_ON ; 
 int /*<<< orphan*/  RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct radeon_encoder* to_radeon_encoder (struct drm_encoder*) ; 

void
radeon_combios_encoder_dpms_scratch_regs(struct drm_encoder *encoder, bool on)
{
	struct drm_device *dev = encoder->dev;
	struct radeon_device *rdev = dev->dev_private;
	struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
	uint32_t bios_6_scratch = RREG32(RADEON_BIOS_6_SCRATCH);

	if (radeon_encoder->devices & (ATOM_DEVICE_TV_SUPPORT)) {
		if (on)
			bios_6_scratch |= RADEON_TV_DPMS_ON;
		else
			bios_6_scratch &= ~RADEON_TV_DPMS_ON;
	}
	if (radeon_encoder->devices & (ATOM_DEVICE_CRT_SUPPORT)) {
		if (on)
			bios_6_scratch |= RADEON_CRT_DPMS_ON;
		else
			bios_6_scratch &= ~RADEON_CRT_DPMS_ON;
	}
	if (radeon_encoder->devices & (ATOM_DEVICE_LCD_SUPPORT)) {
		if (on)
			bios_6_scratch |= RADEON_LCD_DPMS_ON;
		else
			bios_6_scratch &= ~RADEON_LCD_DPMS_ON;
	}
	if (radeon_encoder->devices & (ATOM_DEVICE_DFP_SUPPORT)) {
		if (on)
			bios_6_scratch |= RADEON_DFP_DPMS_ON;
		else
			bios_6_scratch &= ~RADEON_DFP_DPMS_ON;
	}
	WREG32(RADEON_BIOS_6_SCRATCH, bios_6_scratch);
}