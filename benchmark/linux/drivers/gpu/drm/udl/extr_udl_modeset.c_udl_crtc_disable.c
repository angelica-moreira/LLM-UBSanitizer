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
struct drm_crtc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_MODE_DPMS_OFF ; 
 int /*<<< orphan*/  udl_crtc_dpms (struct drm_crtc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void udl_crtc_disable(struct drm_crtc *crtc)
{
	udl_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
}