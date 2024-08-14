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
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 void* alloc_pages (int /*<<< orphan*/ ,int) ; 

void *mempool_alloc_pages(gfp_t gfp_mask, void *pool_data)
{
	int order = (int)(long)pool_data;
	return alloc_pages(gfp_mask, order);
}