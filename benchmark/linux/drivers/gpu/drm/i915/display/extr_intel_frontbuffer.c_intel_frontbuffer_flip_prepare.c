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
struct TYPE_2__ {unsigned int flip_bits; unsigned int busy_bits; int /*<<< orphan*/  lock; } ;
struct drm_i915_private {TYPE_1__ fb_tracking; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

void intel_frontbuffer_flip_prepare(struct drm_i915_private *i915,
				    unsigned frontbuffer_bits)
{
	spin_lock(&i915->fb_tracking.lock);
	i915->fb_tracking.flip_bits |= frontbuffer_bits;
	/* Remove stale busy bits due to the old buffer. */
	i915->fb_tracking.busy_bits &= ~frontbuffer_bits;
	spin_unlock(&i915->fb_tracking.lock);
}