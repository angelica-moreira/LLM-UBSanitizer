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

/* Variables and functions */
 int PAGE_SIZE ; 

__attribute__((used)) static bool page_same_filled(void *ptr, unsigned long *element)
{
	unsigned int pos;
	unsigned long *page;
	unsigned long val;

	page = (unsigned long *)ptr;
	val = page[0];

	for (pos = 1; pos < PAGE_SIZE / sizeof(*page); pos++) {
		if (val != page[pos])
			return false;
	}

	*element = val;

	return true;
}