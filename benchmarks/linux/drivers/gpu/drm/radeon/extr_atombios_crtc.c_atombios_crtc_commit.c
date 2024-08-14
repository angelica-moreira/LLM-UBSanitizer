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
 int /*<<< orphan*/  ATOM_DISABLE ; 
 int /*<<< orphan*/  DRM_MODE_DPMS_ON ; 
 int /*<<< orphan*/  atombios_crtc_dpms (struct drm_crtc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atombios_lock_crtc (struct drm_crtc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void atombios_crtc_commit(struct drm_crtc *crtc)
{
	atombios_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
	atombios_lock_crtc(crtc, ATOM_DISABLE);
}