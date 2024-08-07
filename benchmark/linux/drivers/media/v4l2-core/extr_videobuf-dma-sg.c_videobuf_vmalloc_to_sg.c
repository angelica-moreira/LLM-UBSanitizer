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
struct scatterlist {int dummy; } ;
struct page {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PageHighMem (struct page*) ; 
 int /*<<< orphan*/  array_size (int,int) ; 
 int /*<<< orphan*/  sg_init_table (struct scatterlist*,int) ; 
 int /*<<< orphan*/  sg_set_page (struct scatterlist*,struct page*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfree (struct scatterlist*) ; 
 struct page* vmalloc_to_page (unsigned char*) ; 
 struct scatterlist* vzalloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct scatterlist *videobuf_vmalloc_to_sg(unsigned char *virt,
						  int nr_pages)
{
	struct scatterlist *sglist;
	struct page *pg;
	int i;

	sglist = vzalloc(array_size(nr_pages, sizeof(*sglist)));
	if (NULL == sglist)
		return NULL;
	sg_init_table(sglist, nr_pages);
	for (i = 0; i < nr_pages; i++, virt += PAGE_SIZE) {
		pg = vmalloc_to_page(virt);
		if (NULL == pg)
			goto err;
		BUG_ON(PageHighMem(pg));
		sg_set_page(&sglist[i], pg, PAGE_SIZE, 0);
	}
	return sglist;

err:
	vfree(sglist);
	return NULL;
}