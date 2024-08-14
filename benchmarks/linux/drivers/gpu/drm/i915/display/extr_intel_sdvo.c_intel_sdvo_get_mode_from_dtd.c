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
struct TYPE_4__ {int sync_off_width_high; int v_sync_off_width; int v_sync_off_high; int dtd_flags; scalar_t__ h_sync_width; scalar_t__ h_sync_off; } ;
struct TYPE_3__ {int h_high; int v_high; int clock; scalar_t__ v_blank; scalar_t__ v_active; scalar_t__ h_blank; scalar_t__ h_active; } ;
struct intel_sdvo_dtd {TYPE_2__ part2; TYPE_1__ part1; } ;
struct drm_display_mode {int clock; int /*<<< orphan*/  flags; scalar_t__ vtotal; scalar_t__ vdisplay; scalar_t__ vsync_end; scalar_t__ vsync_start; scalar_t__ htotal; scalar_t__ hdisplay; scalar_t__ hsync_end; scalar_t__ hsync_start; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_MODE_FLAG_INTERLACE ; 
 int /*<<< orphan*/  DRM_MODE_FLAG_NHSYNC ; 
 int /*<<< orphan*/  DRM_MODE_FLAG_NVSYNC ; 
 int /*<<< orphan*/  DRM_MODE_FLAG_PHSYNC ; 
 int /*<<< orphan*/  DRM_MODE_FLAG_PVSYNC ; 
 int DTD_FLAG_HSYNC_POSITIVE ; 
 int DTD_FLAG_INTERLACE ; 
 int DTD_FLAG_VSYNC_POSITIVE ; 
 int /*<<< orphan*/  drm_mode_copy (struct drm_display_mode*,struct drm_display_mode*) ; 
 int /*<<< orphan*/  drm_mode_set_crtcinfo (struct drm_display_mode*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void intel_sdvo_get_mode_from_dtd(struct drm_display_mode *pmode,
					 const struct intel_sdvo_dtd *dtd)
{
	struct drm_display_mode mode = {};

	mode.hdisplay = dtd->part1.h_active;
	mode.hdisplay += ((dtd->part1.h_high >> 4) & 0x0f) << 8;
	mode.hsync_start = mode.hdisplay + dtd->part2.h_sync_off;
	mode.hsync_start += (dtd->part2.sync_off_width_high & 0xc0) << 2;
	mode.hsync_end = mode.hsync_start + dtd->part2.h_sync_width;
	mode.hsync_end += (dtd->part2.sync_off_width_high & 0x30) << 4;
	mode.htotal = mode.hdisplay + dtd->part1.h_blank;
	mode.htotal += (dtd->part1.h_high & 0xf) << 8;

	mode.vdisplay = dtd->part1.v_active;
	mode.vdisplay += ((dtd->part1.v_high >> 4) & 0x0f) << 8;
	mode.vsync_start = mode.vdisplay;
	mode.vsync_start += (dtd->part2.v_sync_off_width >> 4) & 0xf;
	mode.vsync_start += (dtd->part2.sync_off_width_high & 0x0c) << 2;
	mode.vsync_start += dtd->part2.v_sync_off_high & 0xc0;
	mode.vsync_end = mode.vsync_start +
		(dtd->part2.v_sync_off_width & 0xf);
	mode.vsync_end += (dtd->part2.sync_off_width_high & 0x3) << 4;
	mode.vtotal = mode.vdisplay + dtd->part1.v_blank;
	mode.vtotal += (dtd->part1.v_high & 0xf) << 8;

	mode.clock = dtd->part1.clock * 10;

	if (dtd->part2.dtd_flags & DTD_FLAG_INTERLACE)
		mode.flags |= DRM_MODE_FLAG_INTERLACE;
	if (dtd->part2.dtd_flags & DTD_FLAG_HSYNC_POSITIVE)
		mode.flags |= DRM_MODE_FLAG_PHSYNC;
	else
		mode.flags |= DRM_MODE_FLAG_NHSYNC;
	if (dtd->part2.dtd_flags & DTD_FLAG_VSYNC_POSITIVE)
		mode.flags |= DRM_MODE_FLAG_PVSYNC;
	else
		mode.flags |= DRM_MODE_FLAG_NVSYNC;

	drm_mode_set_crtcinfo(&mode, 0);

	drm_mode_copy(pmode, &mode);
}