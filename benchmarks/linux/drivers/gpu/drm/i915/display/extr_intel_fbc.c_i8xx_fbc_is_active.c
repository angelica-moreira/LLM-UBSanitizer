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
 int /*<<< orphan*/  FBC_CONTROL ; 
 int FBC_CTL_EN ; 
 int I915_READ (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool i8xx_fbc_is_active(struct drm_i915_private *dev_priv)
{
	return I915_READ(FBC_CONTROL) & FBC_CTL_EN;
}