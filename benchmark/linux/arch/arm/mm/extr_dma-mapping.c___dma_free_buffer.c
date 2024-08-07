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
 size_t PAGE_SHIFT ; 
 int /*<<< orphan*/  __free_page (struct page*) ; 

__attribute__((used)) static void __dma_free_buffer(struct page *page, size_t size)
{
	struct page *e = page + (size >> PAGE_SHIFT);

	while (page < e) {
		__free_page(page);
		page++;
	}
}