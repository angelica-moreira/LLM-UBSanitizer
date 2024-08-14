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
 int /*<<< orphan*/  DRM_MODE_DPMS_OFF ; 
 int /*<<< orphan*/  drm_i2c_encoder_dpms (struct drm_encoder*,int /*<<< orphan*/ ) ; 

void drm_i2c_encoder_prepare(struct drm_encoder *encoder)
{
	drm_i2c_encoder_dpms(encoder, DRM_MODE_DPMS_OFF);
}