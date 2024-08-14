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
struct intel_gt {int /*<<< orphan*/  scratch; } ;

/* Variables and functions */
 int /*<<< orphan*/  i915_vma_unpin_and_release (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void intel_gt_fini_scratch(struct intel_gt *gt)
{
	i915_vma_unpin_and_release(&gt->scratch, 0);
}