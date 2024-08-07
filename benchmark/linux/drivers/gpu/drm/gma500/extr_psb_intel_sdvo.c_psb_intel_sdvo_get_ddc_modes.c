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
struct psb_intel_sdvo_connector {int dummy; } ;
struct edid {int input; } ;
struct drm_connector {int dummy; } ;

/* Variables and functions */
 int DRM_EDID_INPUT_DIGITAL ; 
 int /*<<< orphan*/  IS_TMDS (struct psb_intel_sdvo_connector*) ; 
 int /*<<< orphan*/  drm_add_edid_modes (struct drm_connector*,struct edid*) ; 
 int /*<<< orphan*/  drm_connector_update_edid_property (struct drm_connector*,struct edid*) ; 
 int /*<<< orphan*/  kfree (struct edid*) ; 
 struct edid* psb_intel_sdvo_get_analog_edid (struct drm_connector*) ; 
 struct edid* psb_intel_sdvo_get_edid (struct drm_connector*) ; 
 struct psb_intel_sdvo_connector* to_psb_intel_sdvo_connector (struct drm_connector*) ; 

__attribute__((used)) static void psb_intel_sdvo_get_ddc_modes(struct drm_connector *connector)
{
	struct edid *edid;

	/* set the bus switch and get the modes */
	edid = psb_intel_sdvo_get_edid(connector);

	/*
	 * Mac mini hack.  On this device, the DVI-I connector shares one DDC
	 * link between analog and digital outputs. So, if the regular SDVO
	 * DDC fails, check to see if the analog output is disconnected, in
	 * which case we'll look there for the digital DDC data.
	 */
	if (edid == NULL)
		edid = psb_intel_sdvo_get_analog_edid(connector);

	if (edid != NULL) {
		struct psb_intel_sdvo_connector *psb_intel_sdvo_connector = to_psb_intel_sdvo_connector(connector);
		bool monitor_is_digital = !!(edid->input & DRM_EDID_INPUT_DIGITAL);
		bool connector_is_digital = !!IS_TMDS(psb_intel_sdvo_connector);

		if (connector_is_digital == monitor_is_digital) {
			drm_connector_update_edid_property(connector, edid);
			drm_add_edid_modes(connector, edid);
		}

		kfree(edid);
	}
}