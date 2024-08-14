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
struct drm_i915_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  valleyview_cleanup_pctx (struct drm_i915_private*) ; 

__attribute__((used)) static void valleyview_cleanup_gt_powersave(struct drm_i915_private *dev_priv)
{
	valleyview_cleanup_pctx(dev_priv);
}