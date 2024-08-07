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
struct jh057n {int /*<<< orphan*/  dev; } ;
struct drm_panel {TYPE_2__* connector; int /*<<< orphan*/  drm; } ;
struct drm_display_mode {int type; int /*<<< orphan*/  height_mm; int /*<<< orphan*/  width_mm; } ;
struct TYPE_7__ {int /*<<< orphan*/  vrefresh; int /*<<< orphan*/  vdisplay; int /*<<< orphan*/  hdisplay; } ;
struct TYPE_5__ {int /*<<< orphan*/  height_mm; int /*<<< orphan*/  width_mm; } ;
struct TYPE_6__ {TYPE_1__ display_info; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEV_ERROR (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int DRM_MODE_TYPE_DRIVER ; 
 int DRM_MODE_TYPE_PREFERRED ; 
 int ENOMEM ; 
 TYPE_3__ default_mode ; 
 struct drm_display_mode* drm_mode_duplicate (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  drm_mode_probed_add (TYPE_2__*,struct drm_display_mode*) ; 
 int /*<<< orphan*/  drm_mode_set_name (struct drm_display_mode*) ; 
 struct jh057n* panel_to_jh057n (struct drm_panel*) ; 

__attribute__((used)) static int jh057n_get_modes(struct drm_panel *panel)
{
	struct jh057n *ctx = panel_to_jh057n(panel);
	struct drm_display_mode *mode;

	mode = drm_mode_duplicate(panel->drm, &default_mode);
	if (!mode) {
		DRM_DEV_ERROR(ctx->dev, "Failed to add mode %ux%u@%u\n",
			      default_mode.hdisplay, default_mode.vdisplay,
			      default_mode.vrefresh);
		return -ENOMEM;
	}

	drm_mode_set_name(mode);

	mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
	panel->connector->display_info.width_mm = mode->width_mm;
	panel->connector->display_info.height_mm = mode->height_mm;
	drm_mode_probed_add(panel->connector, mode);

	return 1;
}