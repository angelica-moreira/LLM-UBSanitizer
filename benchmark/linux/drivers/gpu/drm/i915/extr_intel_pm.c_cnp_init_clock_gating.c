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
 int CNP_PWM_CGE_GATING_DISABLE ; 
 int /*<<< orphan*/  HAS_PCH_CNP (struct drm_i915_private*) ; 
 int I915_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  I915_WRITE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SOUTH_DSPCLK_GATE_D ; 

__attribute__((used)) static void cnp_init_clock_gating(struct drm_i915_private *dev_priv)
{
	if (!HAS_PCH_CNP(dev_priv))
		return;

	/* Display WA #1181 WaSouthDisplayDisablePWMCGEGating: cnp */
	I915_WRITE(SOUTH_DSPCLK_GATE_D, I915_READ(SOUTH_DSPCLK_GATE_D) |
		   CNP_PWM_CGE_GATING_DISABLE);
}