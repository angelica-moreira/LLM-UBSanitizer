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
struct address_space {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PageSwapCache (struct page*) ; 
 struct address_space* page_mapping (struct page*) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

struct address_space *page_mapping_file(struct page *page)
{
	if (unlikely(PageSwapCache(page)))
		return NULL;
	return page_mapping(page);
}