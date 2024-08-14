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
struct page {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __page_cache_release (struct page*) ; 
 int /*<<< orphan*/  free_unref_page (struct page*) ; 
 int /*<<< orphan*/  mem_cgroup_uncharge (struct page*) ; 

__attribute__((used)) static void __put_single_page(struct page *page)
{
	__page_cache_release(page);
	mem_cgroup_uncharge(page);
	free_unref_page(page);
}