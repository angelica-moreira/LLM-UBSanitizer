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
struct i915_vma {int /*<<< orphan*/  private; int /*<<< orphan*/  obj; } ;
struct i915_request {int dummy; } ;

/* Variables and functions */
 int i915_request_await_object (struct i915_request*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i915_vma_lock (struct i915_vma*) ; 
 int i915_vma_move_to_active (struct i915_vma*,struct i915_request*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i915_vma_unlock (struct i915_vma*) ; 
 int intel_engine_pool_mark_active (int /*<<< orphan*/ ,struct i915_request*) ; 
 scalar_t__ unlikely (int) ; 

int intel_emit_vma_mark_active(struct i915_vma *vma, struct i915_request *rq)
{
	int err;

	i915_vma_lock(vma);
	err = i915_request_await_object(rq, vma->obj, false);
	if (err == 0)
		err = i915_vma_move_to_active(vma, rq, 0);
	i915_vma_unlock(vma);
	if (unlikely(err))
		return err;

	return intel_engine_pool_mark_active(vma->private, rq);
}