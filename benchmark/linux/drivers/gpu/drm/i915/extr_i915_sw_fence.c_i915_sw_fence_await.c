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
struct i915_sw_fence {int /*<<< orphan*/  pending; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int) ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debug_fence_assert (struct i915_sw_fence*) ; 

void i915_sw_fence_await(struct i915_sw_fence *fence)
{
	debug_fence_assert(fence);
	WARN_ON(atomic_inc_return(&fence->pending) <= 1);
}