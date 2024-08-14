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
 int /*<<< orphan*/  atmel_hlcdc_crtc_finish_page_flip (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_crtc_handle_vblank (struct drm_crtc*) ; 
 int /*<<< orphan*/  drm_crtc_to_atmel_hlcdc_crtc (struct drm_crtc*) ; 

void atmel_hlcdc_crtc_irq(struct drm_crtc *c)
{
	drm_crtc_handle_vblank(c);
	atmel_hlcdc_crtc_finish_page_flip(drm_crtc_to_atmel_hlcdc_crtc(c));
}