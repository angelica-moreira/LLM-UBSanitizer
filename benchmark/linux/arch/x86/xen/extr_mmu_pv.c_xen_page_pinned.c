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
 int PagePinned (struct page*) ; 
 scalar_t__ static_branch_likely (int /*<<< orphan*/ *) ; 
 struct page* virt_to_page (void*) ; 
 int /*<<< orphan*/  xen_struct_pages_ready ; 

__attribute__((used)) static bool xen_page_pinned(void *ptr)
{
	if (static_branch_likely(&xen_struct_pages_ready)) {
		struct page *page = virt_to_page(ptr);

		return PagePinned(page);
	}
	return true;
}