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

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* kzalloc (size_t,int /*<<< orphan*/ ) ; 
 void* kzalloc_node (size_t,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void *xgbe_alloc_node(size_t size, int node)
{
	void *mem;

	mem = kzalloc_node(size, GFP_KERNEL, node);
	if (!mem)
		mem = kzalloc(size, GFP_KERNEL);

	return mem;
}