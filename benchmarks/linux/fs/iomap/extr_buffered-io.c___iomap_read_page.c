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
struct inode {struct address_space* i_mapping; } ;
struct address_space {int dummy; } ;
typedef  int loff_t ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 struct page* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct page*) ; 
 int PAGE_SHIFT ; 
 int /*<<< orphan*/  PageUptodate (struct page*) ; 
 int /*<<< orphan*/  put_page (struct page*) ; 
 struct page* read_mapping_page (struct address_space*,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct page *
__iomap_read_page(struct inode *inode, loff_t offset)
{
	struct address_space *mapping = inode->i_mapping;
	struct page *page;

	page = read_mapping_page(mapping, offset >> PAGE_SHIFT, NULL);
	if (IS_ERR(page))
		return page;
	if (!PageUptodate(page)) {
		put_page(page);
		return ERR_PTR(-EIO);
	}
	return page;
}