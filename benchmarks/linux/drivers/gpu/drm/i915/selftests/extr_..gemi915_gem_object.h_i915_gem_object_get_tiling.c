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
struct drm_i915_gem_object {unsigned int tiling_and_stride; } ;

/* Variables and functions */
 unsigned int TILING_MASK ; 

__attribute__((used)) static inline unsigned int
i915_gem_object_get_tiling(const struct drm_i915_gem_object *obj)
{
	return obj->tiling_and_stride & TILING_MASK;
}