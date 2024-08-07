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
struct i915_gpu_state {int /*<<< orphan*/  params; } ;

/* Variables and functions */
 int /*<<< orphan*/  i915_modparams ; 
 int /*<<< orphan*/  i915_params_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void capture_params(struct i915_gpu_state *error)
{
	i915_params_copy(&error->params, &i915_modparams);
}