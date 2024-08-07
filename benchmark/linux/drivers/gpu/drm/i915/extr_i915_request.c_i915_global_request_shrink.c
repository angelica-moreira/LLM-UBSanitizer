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
struct TYPE_2__ {int /*<<< orphan*/  slab_requests; int /*<<< orphan*/  slab_execute_cbs; int /*<<< orphan*/  slab_dependencies; } ;

/* Variables and functions */
 TYPE_1__ global ; 
 int /*<<< orphan*/  kmem_cache_shrink (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void i915_global_request_shrink(void)
{
	kmem_cache_shrink(global.slab_dependencies);
	kmem_cache_shrink(global.slab_execute_cbs);
	kmem_cache_shrink(global.slab_requests);
}