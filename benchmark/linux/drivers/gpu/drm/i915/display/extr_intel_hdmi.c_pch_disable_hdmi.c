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
struct intel_encoder {int dummy; } ;
struct intel_crtc_state {scalar_t__ has_audio; } ;
struct drm_connector_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  intel_audio_codec_disable (struct intel_encoder*,struct intel_crtc_state const*,struct drm_connector_state const*) ; 

__attribute__((used)) static void pch_disable_hdmi(struct intel_encoder *encoder,
			     const struct intel_crtc_state *old_crtc_state,
			     const struct drm_connector_state *old_conn_state)
{
	if (old_crtc_state->has_audio)
		intel_audio_codec_disable(encoder,
					  old_crtc_state, old_conn_state);
}