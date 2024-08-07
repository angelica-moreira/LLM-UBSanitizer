#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;
struct intel_crtc {TYPE_1__ base; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* update_wm ) (struct intel_crtc*) ;} ;
struct drm_i915_private {TYPE_2__ display; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct intel_crtc*) ; 
 struct drm_i915_private* to_i915 (int /*<<< orphan*/ ) ; 

void intel_update_watermarks(struct intel_crtc *crtc)
{
	struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);

	if (dev_priv->display.update_wm)
		dev_priv->display.update_wm(crtc);
}