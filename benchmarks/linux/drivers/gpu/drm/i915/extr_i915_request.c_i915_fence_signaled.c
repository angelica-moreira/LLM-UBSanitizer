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
struct dma_fence {int dummy; } ;

/* Variables and functions */
 int i915_request_completed (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_request (struct dma_fence*) ; 

__attribute__((used)) static bool i915_fence_signaled(struct dma_fence *fence)
{
	return i915_request_completed(to_request(fence));
}