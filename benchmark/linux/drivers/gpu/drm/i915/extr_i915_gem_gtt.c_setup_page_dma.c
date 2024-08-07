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
struct i915_page_dma {int dummy; } ;
struct i915_address_space {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __GFP_HIGHMEM ; 
 int __setup_page_dma (struct i915_address_space*,struct i915_page_dma*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int setup_page_dma(struct i915_address_space *vm,
			  struct i915_page_dma *p)
{
	return __setup_page_dma(vm, p, __GFP_HIGHMEM);
}