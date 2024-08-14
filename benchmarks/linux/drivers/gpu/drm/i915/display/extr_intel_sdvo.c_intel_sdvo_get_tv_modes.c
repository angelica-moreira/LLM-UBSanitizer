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
typedef  int /*<<< orphan*/  tv_res ;
struct intel_sdvo_sdtv_resolution_request {int dummy; } ;
struct intel_sdvo {int /*<<< orphan*/  attached_output; } ;
struct drm_display_mode {int dummy; } ;
struct TYPE_4__ {int mode; } ;
struct drm_connector_state {TYPE_2__ tv; } ;
struct TYPE_3__ {int /*<<< orphan*/  id; } ;
struct drm_connector {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; TYPE_1__ base; struct drm_connector_state* state; } ;
typedef  int /*<<< orphan*/  format_map ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDVO_CMD_GET_SDTV_RESOLUTION_SUPPORT ; 
 struct drm_display_mode* drm_mode_duplicate (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_mode_probed_add (struct drm_connector*,struct drm_display_mode*) ; 
 struct intel_sdvo* intel_attached_sdvo (struct drm_connector*) ; 
 int /*<<< orphan*/  intel_sdvo_read_response (struct intel_sdvo*,int*,int) ; 
 int /*<<< orphan*/  intel_sdvo_set_target_output (struct intel_sdvo*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  intel_sdvo_write_cmd (struct intel_sdvo*,int /*<<< orphan*/ ,struct intel_sdvo_sdtv_resolution_request*,int) ; 
 int /*<<< orphan*/  memcpy (struct intel_sdvo_sdtv_resolution_request*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  min (int,int) ; 
 int /*<<< orphan*/ * sdvo_tv_modes ; 

__attribute__((used)) static void intel_sdvo_get_tv_modes(struct drm_connector *connector)
{
	struct intel_sdvo *intel_sdvo = intel_attached_sdvo(connector);
	const struct drm_connector_state *conn_state = connector->state;
	struct intel_sdvo_sdtv_resolution_request tv_res;
	u32 reply = 0, format_map = 0;
	int i;

	DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
		      connector->base.id, connector->name);

	/*
	 * Read the list of supported input resolutions for the selected TV
	 * format.
	 */
	format_map = 1 << conn_state->tv.mode;
	memcpy(&tv_res, &format_map,
	       min(sizeof(format_map), sizeof(struct intel_sdvo_sdtv_resolution_request)));

	if (!intel_sdvo_set_target_output(intel_sdvo, intel_sdvo->attached_output))
		return;

	BUILD_BUG_ON(sizeof(tv_res) != 3);
	if (!intel_sdvo_write_cmd(intel_sdvo,
				  SDVO_CMD_GET_SDTV_RESOLUTION_SUPPORT,
				  &tv_res, sizeof(tv_res)))
		return;
	if (!intel_sdvo_read_response(intel_sdvo, &reply, 3))
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