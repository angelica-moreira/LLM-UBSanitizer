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
 unsigned long PAGE_SIZE ; 
 void* kmap_atomic (struct page*) ; 
 int /*<<< orphan*/  kunmap_atomic (void*) ; 
 int /*<<< orphan*/  memcpy (char*,void*,unsigned long) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,unsigned long) ; 
 unsigned long offset_in_page (char*) ; 
 struct page* vmalloc_to_page (char*) ; 

__attribute__((used)) static int aligned_vread(char *buf, char *addr, unsigned long count)
{
	struct page *p;
	int copied = 0;

	while (count) {
		unsigned long offset, length;

		offset = offset_in_page(addr);
		length = PAGE_SIZE - offset;
		if (length > count)
			length = count;
		p = vmalloc_to_page(addr);
		/*
		 * To do safe access to this _mapped_ area, we need
		 * lock. But adding lock here means that we need to add
		 * overhead of vmalloc()/vfree() calles for this _debug_
		 * interface, rarely used. Instead of that, we'll use
		 * kmap() and get small overhead in this access function.
		 */
		if (p) {
			/*
			 * we can expect USER0 is not used (see vread/vwrite's
			 * function description)
			 */
			void *map = kmap_atomic(p);
			memcpy(buf, map + offset, length);
			kunmap_atomic(map);
		} else
			memset(buf, 0, length);

		addr += length;
		buf += length;
		copied += length;
		count -= length;
	}
	return copied;
}