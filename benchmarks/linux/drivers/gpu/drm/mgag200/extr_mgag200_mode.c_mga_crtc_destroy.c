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
struct mga_crtc {int dummy; } ;
struct drm_crtc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_crtc_cleanup (struct drm_crtc*) ; 
 int /*<<< orphan*/  kfree (struct mga_crtc*) ; 
 struct mga_crtc* to_mga_crtc (struct drm_crtc*) ; 

__attribute__((used)) static void mga_crtc_destroy(struct drm_crtc *crtc)
{
	struct mga_crtc *mga_crtc = to_mga_crtc(crtc);

	drm_crtc_cleanup(crtc);
	kfree(mga_crtc);
}