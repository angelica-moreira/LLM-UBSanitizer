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
struct radeon_encoder_atom_dig {int /*<<< orphan*/  afmt; } ;
struct radeon_encoder {struct radeon_encoder_atom_dig* enc_priv; } ;
struct drm_encoder {int dummy; } ;
struct drm_display_mode {int /*<<< orphan*/  clock; } ;
struct drm_connector {int dummy; } ;

/* Variables and functions */
 scalar_t__ drm_detect_monitor_audio (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radeon_audio_select_pin (struct drm_encoder*) ; 
 int /*<<< orphan*/  radeon_audio_set_audio_packet (struct drm_encoder*) ; 
 scalar_t__ radeon_audio_set_avi_packet (struct drm_encoder*,struct drm_display_mode*) ; 
 int /*<<< orphan*/  radeon_audio_set_dto (struct drm_encoder*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radeon_audio_set_mute (struct drm_encoder*,int) ; 
 int /*<<< orphan*/  radeon_audio_set_vbi_packet (struct drm_encoder*) ; 
 int /*<<< orphan*/  radeon_audio_update_acr (struct drm_encoder*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radeon_audio_write_latency_fields (struct drm_encoder*,struct drm_display_mode*) ; 
 int /*<<< orphan*/  radeon_audio_write_sad_regs (struct drm_encoder*) ; 
 int /*<<< orphan*/  radeon_audio_write_speaker_allocation (struct drm_encoder*) ; 
 int /*<<< orphan*/  radeon_connector_edid (struct drm_connector*) ; 
 struct drm_connector* radeon_get_connector_for_encoder (struct drm_encoder*) ; 
 int /*<<< orphan*/  radeon_hdmi_set_color_depth (struct drm_encoder*) ; 
 struct radeon_encoder* to_radeon_encoder (struct drm_encoder*) ; 

__attribute__((used)) static void radeon_audio_hdmi_mode_set(struct drm_encoder *encoder,
				       struct drm_display_mode *mode)
{
	struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
	struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
	struct drm_connector *connector = radeon_get_connector_for_encoder(encoder);

	if (!dig || !dig->afmt)
		return;

	if (!connector)
		return;

	if (drm_detect_monitor_audio(radeon_connector_edid(connector))) {
		radeon_audio_set_mute(encoder, true);

		radeon_audio_write_speaker_allocation(encoder);
		radeon_audio_write_sad_regs(encoder);
		radeon_audio_write_latency_fields(encoder, mode);
		radeon_audio_set_dto(encoder, mode->clock);
		radeon_audio_set_vbi_packet(encoder);
		radeon_hdmi_set_color_depth(encoder);
		radeon_audio_update_acr(encoder, mode->clock);
		radeon_audio_set_audio_packet(encoder);
		radeon_audio_select_pin(encoder);

		if (radeon_audio_set_avi_packet(encoder, mode) < 0)
			return;

		radeon_audio_set_mute(encoder, false);
	} else {
		radeon_hdmi_set_color_depth(encoder);

		if (radeon_audio_set_avi_packet(encoder, mode) < 0)
			return;
	}
}