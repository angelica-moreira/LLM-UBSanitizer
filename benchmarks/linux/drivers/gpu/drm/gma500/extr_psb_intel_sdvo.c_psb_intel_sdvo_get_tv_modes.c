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
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  tv_res ;
struct psb_intel_sdvo_sdtv_resolution_request {int dummy; } ;
struct psb_intel_sdvo {int tv_format_index; int /*<<< orphan*/  attached_output; } ;
struct drm_display_mode {int dummy; } ;
struct drm_connector {int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  format_map ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  SDVO_CMD_GET_SDTV_RESOLUTION_SUPPORT ; 
 struct drm_display_mode* drm_mode_duplicate (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_mode_probed_add (struct drm_connector*,struct drm_display_mode*) ; 
 struct psb_intel_sdvo* intel_attached_sdvo (struct drm_connector*) ; 
 int /*<<< orphan*/  memcpy (struct psb_intel_sdvo_sdtv_resolution_request*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  min (int,int) ; 
 int /*<<< orphan*/  psb_intel_sdvo_read_response (struct psb_intel_sdvo*,int*,int) ; 
 int /*<<< orphan*/  psb_intel_sdvo_set_target_output (struct psb_intel_sdvo*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  psb_intel_sdvo_write_cmd (struct psb_intel_sdvo*,int /*<<< orphan*/ ,struct psb_intel_sdvo_sdtv_resolution_request*,int) ; 
 int /*<<< orphan*/ * sdvo_tv_modes ; 

__attribute__((used)) static void psb_intel_sdvo_get_tv_modes(struct drm_connector *connector)
{
	struct psb_intel_sdvo *psb_intel_sdvo = intel_attached_sdvo(connector);
	struct psb_intel_sdvo_sdtv_resolution_request tv_res;
	uint32_t reply = 0, format_map = 0;
	int i;

	/* Read the list of supported input resolutions for the selected TV
	 * format.
	 */
	format_map = 1 << psb_intel_sdvo->tv_format_index;
	memcpy(&tv_res, &format_map,
	       min(sizeof(format_map), sizeof(struct psb_intel_sdvo_sdtv_resolution_request)));

	if (!psb_intel_sdvo_set_target_output(psb_intel_sdvo, psb_intel_sdvo->attached_output))
		return;

	BUILD_BUG_ON(sizeof(tv_res) != 3);
	if (!psb_intel_sdvo_write_cmd(psb_intel_sdvo,
				  SDVO_CMD_GET_SDTV_RESOLUTION_SUPPORT,
				  &tv_res, sizeof(tv_res)))
		return;
	if (!psb_intel_sdvo_read_response(psb_intel_sdvo, &reply, 3))
		return;

	for (i = 0; i < ARRAY_SIZE(sdvo_tv_modes); i++)
		if (reply & (1 << i)) {
			struct drm_display_mode *nmode;
			nmode = drm_mode_duplicate(connector->dev,
						   &sdvo_tv_modes[i]);
			if (nmode)
				drm_mode_probed_add(connector, nmode);
		}
}