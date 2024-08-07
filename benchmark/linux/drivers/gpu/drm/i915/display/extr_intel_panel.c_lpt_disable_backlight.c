#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;
struct intel_connector {TYPE_1__ base; } ;
struct drm_i915_private {int dummy; } ;
struct drm_connector_state {int /*<<< orphan*/  connector; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLC_PWM_CPU_CTL2 ; 
 int /*<<< orphan*/  BLC_PWM_PCH_CTL1 ; 
 int BLM_PCH_PWM_ENABLE ; 
 int BLM_PWM_ENABLE ; 
 int /*<<< orphan*/  DRM_DEBUG_KMS (char*) ; 
 int I915_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  I915_WRITE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  intel_panel_actually_set_backlight (struct drm_connector_state const*,int /*<<< orphan*/ ) ; 
 struct drm_i915_private* to_i915 (int /*<<< orphan*/ ) ; 
 struct intel_connector* to_intel_connector (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lpt_disable_backlight(const struct drm_connector_state *old_conn_state)
{
	struct intel_connector *connector = to_intel_connector(old_conn_state->connector);
	struct drm_i915_private *dev_priv = to_i915(connector->base.dev);
	u32 tmp;

	intel_panel_actually_set_backlight(old_conn_state, 0);

	/*
	 * Although we don't support or enable CPU PWM with LPT/SPT based
	 * systems, it may have been enabled prior to loading the
	 * driver. Disable to avoid warnings on LCPLL disable.
	 *
	 * This needs rework if we need to add support for CPU PWM on PCH split
	 * platforms.
	 */
	tmp = I915_READ(BLC_PWM_CPU_CTL2);
	if (tmp & BLM_PWM_ENABLE) {
		DRM_DEBUG_KMS("cpu backlight was enabled, disabling\n");
		I915_WRITE(BLC_PWM_CPU_CTL2, tmp & ~BLM_PWM_ENABLE);
	}

	tmp = I915_READ(BLC_PWM_PCH_CTL1);
	I915_WRITE(BLC_PWM_PCH_CTL1, tmp & ~BLM_PCH_PWM_ENABLE);
}