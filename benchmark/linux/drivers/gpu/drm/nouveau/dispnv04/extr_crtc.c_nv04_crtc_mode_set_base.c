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
struct drm_framebuffer {int dummy; } ;
struct drm_crtc {int dummy; } ;

/* Variables and functions */
 int nv04_crtc_do_mode_set_base (struct drm_crtc*,struct drm_framebuffer*,int,int,int) ; 
 int nv_crtc_swap_fbs (struct drm_crtc*,struct drm_framebuffer*) ; 

__attribute__((used)) static int
nv04_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
			struct drm_framebuffer *old_fb)
{
	int ret = nv_crtc_swap_fbs(crtc, old_fb);
	if (ret)
		return ret;
	return nv04_crtc_do_mode_set_base(crtc, old_fb, x, y, false);
}