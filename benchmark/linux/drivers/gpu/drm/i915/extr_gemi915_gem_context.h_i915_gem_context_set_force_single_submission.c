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
struct i915_gem_context {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONTEXT_FORCE_SINGLE_SUBMISSION ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void i915_gem_context_set_force_single_submission(struct i915_gem_context *ctx)
{
	__set_bit(CONTEXT_FORCE_SINGLE_SUBMISSION, &ctx->flags);
}