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
 int /*<<< orphan*/  DRM_MODE_DPMS_ON ; 
 int /*<<< orphan*/  radeon_atom_encoder_dpms (struct drm_encoder*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radeon_atom_output_lock (struct drm_encoder*,int) ; 

__attribute__((used)) static void radeon_atom_encoder_commit(struct drm_encoder *encoder)
{
	/* need to call this here as we need the crtc set up */
	radeon_atom_encoder_dpms(encoder, DRM_MODE_DPMS_ON);
	radeon_atom_output_lock(encoder, false);
}