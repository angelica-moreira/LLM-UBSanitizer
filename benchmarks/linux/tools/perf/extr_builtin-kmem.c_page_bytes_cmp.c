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
struct page_stat {scalar_t__ alloc_bytes; } ;

/* Variables and functions */

__attribute__((used)) static int page_bytes_cmp(void *a, void *b)
{
	struct page_stat *l = a;
	struct page_stat *r = b;

	if (l->alloc_bytes < r->alloc_bytes)
		return -1;
	else if (l->alloc_bytes > r->alloc_bytes)
		return 1;
	return 0;
}