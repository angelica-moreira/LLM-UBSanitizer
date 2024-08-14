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
struct drm_encoder {int dummy; } ;
struct drm_connector {int connector_type; } ;
struct amdgpu_encoder {scalar_t__ encoder_id; } ;
struct amdgpu_connector_atom_dig {int /*<<< orphan*/  dp_sink_type; } ;
struct amdgpu_connector {int /*<<< orphan*/  audio; struct amdgpu_connector_atom_dig* con_priv; int /*<<< orphan*/  use_digital; } ;

/* Variables and functions */
 int /*<<< orphan*/  AMDGPU_AUDIO_AUTO ; 
 int /*<<< orphan*/  AMDGPU_AUDIO_ENABLE ; 
 int ATOM_ENCODER_MODE_CRT ; 
 int ATOM_ENCODER_MODE_DP ; 
 int ATOM_ENCODER_MODE_DVI ; 
 int ATOM_ENCODER_MODE_DVO ; 
 int ATOM_ENCODER_MODE_HDMI ; 
 int ATOM_ENCODER_MODE_LVDS ; 
 int ATOM_ENCODER_MODE_TV ; 
 int /*<<< orphan*/  CONNECTOR_OBJECT_ID_DISPLAYPORT ; 
 int /*<<< orphan*/  CONNECTOR_OBJECT_ID_eDP ; 
#define  DRM_MODE_CONNECTOR_9PinDIN 139 
#define  DRM_MODE_CONNECTOR_Composite 138 
#define  DRM_MODE_CONNECTOR_DVIA 137 
#define  DRM_MODE_CONNECTOR_DVID 136 
#define  DRM_MODE_CONNECTOR_DVII 135 
#define  DRM_MODE_CONNECTOR_DisplayPort 134 
#define  DRM_MODE_CONNECTOR_HDMIA 133 
#define  DRM_MODE_CONNECTOR_HDMIB 132 
#define  DRM_MODE_CONNECTOR_LVDS 131 
#define  DRM_MODE_CONNECTOR_SVIDEO 130 
#define  DRM_MODE_CONNECTOR_VGA 129 
#define  DRM_MODE_CONNECTOR_eDP 128 
 scalar_t__ ENCODER_OBJECT_ID_INTERNAL_DVO1 ; 
 scalar_t__ ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1 ; 
 scalar_t__ ENCODER_OBJECT_ID_NONE ; 
 int /*<<< orphan*/  amdgpu_audio ; 
 int /*<<< orphan*/  amdgpu_connector_edid (struct drm_connector*) ; 
 scalar_t__ amdgpu_encoder_get_dp_bridge_encoder_id (struct drm_encoder*) ; 
 struct drm_connector* amdgpu_get_connector_for_encoder (struct drm_encoder*) ; 
 struct drm_connector* amdgpu_get_connector_for_encoder_init (struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_detect_hdmi_monitor (int /*<<< orphan*/ ) ; 
 struct amdgpu_connector* to_amdgpu_connector (struct drm_connector*) ; 
 struct amdgpu_encoder* to_amdgpu_encoder (struct drm_encoder*) ; 

int amdgpu_atombios_encoder_get_encoder_mode(struct drm_encoder *encoder)
{
	struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
	struct drm_connector *connector;
	struct amdgpu_connector *amdgpu_connector;
	struct amdgpu_connector_atom_dig *dig_connector;

	/* dp bridges are always DP */
	if (amdgpu_encoder_get_dp_bridge_encoder_id(encoder) != ENCODER_OBJECT_ID_NONE)
		return ATOM_ENCODER_MODE_DP;

	/* DVO is always DVO */
	if ((amdgpu_encoder->encoder_id == ENCODER_OBJECT_ID_INTERNAL_DVO1) ||
	    (amdgpu_encoder->encoder_id == ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1))
		return ATOM_ENCODER_MODE_DVO;

	connector = amdgpu_get_connector_for_encoder(encoder);
	/* if we don't have an active device yet, just use one of
	 * the connectors tied to the encoder.
	 */
	if (!connector)
		connector = amdgpu_get_connector_for_encoder_init(encoder);
	amdgpu_connector = to_amdgpu_connector(connector);

	switch (connector->connector_type) {
	case DRM_MODE_CONNECTOR_DVII:
	case DRM_MODE_CONNECTOR_HDMIB: /* HDMI-B is basically DL-DVI; analog works fine */
		if (amdgpu_audio != 0) {
			if (amdgpu_connector->use_digital &&
			    (amdgpu_connector->audio == AMDGPU_AUDIO_ENABLE))
				return ATOM_ENCODER_MODE_HDMI;
			else if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector)) &&
				 (amdgpu_connector->audio == AMDGPU_AUDIO_AUTO))
				return ATOM_ENCODER_MODE_HDMI;
			else if (amdgpu_connector->use_digital)
				return ATOM_ENCODER_MODE_DVI;
			else
				return ATOM_ENCODER_MODE_CRT;
		} else if (amdgpu_connector->use_digital) {
			return ATOM_ENCODER_MODE_DVI;
		} else {
			return ATOM_ENCODER_MODE_CRT;
		}
		break;
	case DRM_MODE_CONNECTOR_DVID:
	case DRM_MODE_CONNECTOR_HDMIA:
	default:
		if (amdgpu_audio != 0) {
			if (amdgpu_connector->audio == AMDGPU_AUDIO_ENABLE)
				return ATOM_ENCODER_MODE_HDMI;
			else if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector)) &&
				 (amdgpu_connector->audio == AMDGPU_AUDIO_AUTO))
				return ATOM_ENCODER_MODE_HDMI;
			else
				return ATOM_ENCODER_MODE_DVI;
		} else {
			return ATOM_ENCODER_MODE_DVI;
		}
		break;
	case DRM_MODE_CONNECTOR_LVDS:
		return ATOM_ENCODER_MODE_LVDS;
		break;
	case DRM_MODE_CONNECTOR_DisplayPort:
		dig_connector = amdgpu_connector->con_priv;
		if ((dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) ||
		    (dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_eDP)) {
			return ATOM_ENCODER_MODE_DP;
		} else if (amdgpu_audio != 0) {
			if (amdgpu_connector->audio == AMDGPU_AUDIO_ENABLE)
				return ATOM_ENCODER_MODE_HDMI;
			else if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector)) &&
				 (amdgpu_connector->audio == AMDGPU_AUDIO_AUTO))
				return ATOM_ENCODER_MODE_HDMI;
			else
				return ATOM_ENCODER_MODE_DVI;
		} else {
			return ATOM_ENCODER_MODE_DVI;
		}
		break;
	case DRM_MODE_CONNECTOR_eDP:
		return ATOM_ENCODER_MODE_DP;
	case DRM_MODE_CONNECTOR_DVIA:
	case DRM_MODE_CONNECTOR_VGA:
		return ATOM_ENCODER_MODE_CRT;
		break;
	case DRM_MODE_CONNECTOR_Composite:
	case DRM_MODE_CONNECTOR_SVIDEO:
	case DRM_MODE_CONNECTOR_9PinDIN:
		/* fix me */
		return ATOM_ENCODER_MODE_TV;
		/*return ATOM_ENCODER_MODE_CV;*/
		break;
	}
}