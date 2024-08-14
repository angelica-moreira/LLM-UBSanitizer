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

/* Variables and functions */
 int /*<<< orphan*/  vc4_hdmi_set_avi_infoframe (struct drm_encoder*) ; 
 int /*<<< orphan*/  vc4_hdmi_set_spd_infoframe (struct drm_encoder*) ; 

__attribute__((used)) static void vc4_hdmi_set_infoframes(struct drm_encoder *encoder)
{
	vc4_hdmi_set_avi_infoframe(encoder);
	vc4_hdmi_set_spd_infoframe(encoder);
}