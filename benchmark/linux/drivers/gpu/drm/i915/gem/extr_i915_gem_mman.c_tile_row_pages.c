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
struct drm_i915_gem_object {int dummy; } ;

/* Variables and functions */
 unsigned int PAGE_SHIFT ; 
 unsigned int i915_gem_object_get_tile_row_size (struct drm_i915_gem_object const*) ; 

__attribute__((used)) static unsigned int tile_row_pages(const struct drm_i915_gem_object *obj)
{
	return i915_gem_object_get_tile_row_size(obj) >> PAGE_SHIFT;
}