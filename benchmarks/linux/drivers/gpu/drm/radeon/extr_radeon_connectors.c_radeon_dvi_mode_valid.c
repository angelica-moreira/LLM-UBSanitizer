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
struct TYPE_2__ {int max_pixel_clock; } ;
struct radeon_device {scalar_t__ family; TYPE_1__ clock; } ;
struct radeon_connector {scalar_t__ connector_object_id; scalar_t__ use_digital; } ;
struct drm_display_mode {int clock; } ;
struct drm_device {struct radeon_device* dev_private; } ;
struct drm_connector {struct drm_device* dev; } ;
typedef  enum drm_mode_status { ____Placeholder_drm_mode_status } drm_mode_status ;

/* Variables and functions */
 scalar_t__ ASIC_IS_DCE6 (struct radeon_device*) ; 
 scalar_t__ CHIP_RV100 ; 
 scalar_t__ CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D ; 
 scalar_t__ CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I ; 
 scalar_t__ CONNECTOR_OBJECT_ID_HDMI_TYPE_B ; 
 int MODE_CLOCK_HIGH ; 
 int MODE_OK ; 
 scalar_t__ drm_detect_hdmi_monitor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radeon_connector_edid (struct drm_connector*) ; 
 struct radeon_connector* to_radeon_connector (struct drm_connector*) ; 

__attribute__((used)) static enum drm_mode_status radeon_dvi_mode_valid(struct drm_connector *connector,
				  struct drm_display_mode *mode)
{
	struct drm_device *dev = connector->dev;
	struct radeon_device *rdev = dev->dev_private;
	struct radeon_connector *radeon_connector = to_radeon_connector(connector);

	/* XXX check mode bandwidth */

	/* clocks over 135 MHz have heat issues with DVI on RV100 */
	if (radeon_connector->use_digital &&
	    (rdev->family == CHIP_RV100) &&
	    (mode->clock > 135000))
		return MODE_CLOCK_HIGH;

	if (radeon_connector->use_digital && (mode->clock > 165000)) {
		if ((radeon_connector->connector_object_id == CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I) ||
		    (radeon_connector->connector_object_id == CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D) ||
		    (radeon_connector->connector_object_id == CONNECTOR_OBJECT_ID_HDMI_TYPE_B))
			return MODE_OK;
		else if (ASIC_IS_DCE6(rdev) && drm_detect_hdmi_monitor(radeon_connector_edid(connector))) {
			/* HDMI 1.3+ supports max clock of 340 Mhz */
			if (mode->clock > 340000)
				return MODE_CLOCK_HIGH;
			else
				return MODE_OK;
		} else {
			return MODE_CLOCK_HIGH;
		}
	}

	/* check against the max pixel clock */
	if ((mode->clock / 10) > rdev->clock.max_pixel_clock)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}