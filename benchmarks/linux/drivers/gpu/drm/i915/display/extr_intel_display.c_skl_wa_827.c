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
 int /*<<< orphan*/  CLKGATE_DIS_PSL (int) ; 
 int DUPS1_GATING_DIS ; 
 int DUPS2_GATING_DIS ; 
 int I915_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  I915_WRITE (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
skl_wa_827(struct drm_i915_private *dev_priv, int pipe, bool enable)
{
	if (enable)
		I915_WRITE(CLKGATE_DIS_PSL(pipe),
			   I915_READ(CLKGATE_DIS_PSL(pipe)) |
			   DUPS1_GATING_DIS | DUPS2_GATING_DIS);
	else
		I915_WRITE(CLKGATE_DIS_PSL(pipe),
			   I915_READ(CLKGATE_DIS_PSL(pipe)) &
			   ~(DUPS1_GATING_DIS | DUPS2_GATING_DIS));
}