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
struct intel_uc {int /*<<< orphan*/  load_err_log; } ;
struct drm_i915_gem_object {int dummy; } ;

/* Variables and functions */
 struct drm_i915_gem_object* fetch_and_zero (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i915_gem_object_put (struct drm_i915_gem_object*) ; 

__attribute__((used)) static void __uc_free_load_err_log(struct intel_uc *uc)
{
	struct drm_i915_gem_object *log = fetch_and_zero(&uc->load_err_log);

	if (log)
		i915_gem_object_put(log);
}