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
 int /*<<< orphan*/  EIO ; 
 struct page* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IS_ERR (struct page*) ; 
 int /*<<< orphan*/  PageError (struct page*) ; 
 int /*<<< orphan*/  kmap (struct page*) ; 
 int /*<<< orphan*/  ntfs_unmap_page (struct page*) ; 
 struct page* read_mapping_page (struct address_space*,unsigned long,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct page *ntfs_map_page(struct address_space *mapping,
		unsigned long index)
{
	struct page *page = read_mapping_page(mapping, index, NULL);

	if (!IS_ERR(page)) {
		kmap(page);
		if (!PageError(page))
			return page;
		ntfs_unmap_page(page);
		return ERR_PTR(-EIO);
	}
	return page;
}