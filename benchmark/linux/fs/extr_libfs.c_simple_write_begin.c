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
struct file {int dummy; } ;
struct address_space {int dummy; } ;
typedef  unsigned int pgoff_t ;
typedef  unsigned int loff_t ;

/* Variables and functions */
 int ENOMEM ; 
 unsigned int PAGE_SHIFT ; 
 unsigned int PAGE_SIZE ; 
 int /*<<< orphan*/  PageUptodate (struct page*) ; 
 struct page* grab_cache_page_write_begin (struct address_space*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  zero_user_segments (struct page*,int /*<<< orphan*/ ,unsigned int,unsigned int,unsigned int) ; 

int simple_write_begin(struct file *file, struct address_space *mapping,
			loff_t pos, unsigned len, unsigned flags,
			struct page **pagep, void **fsdata)
{
	struct page *page;
	pgoff_t index;

	index = pos >> PAGE_SHIFT;

	page = grab_cache_page_write_begin(mapping, index, flags);
	if (!page)
		return -ENOMEM;

	*pagep = page;

	if (!PageUptodate(page) && (len != PAGE_SIZE)) {
		unsigned from = pos & (PAGE_SIZE - 1);

		zero_user_segments(page, 0, from, from + len, PAGE_SIZE);
	}
	return 0;
}