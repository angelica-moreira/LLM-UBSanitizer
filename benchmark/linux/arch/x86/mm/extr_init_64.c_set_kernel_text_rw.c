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
 unsigned long PAGE_SHIFT ; 
 unsigned long PFN_ALIGN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __stop___ex_table ; 
 int /*<<< orphan*/  _text ; 
 int /*<<< orphan*/  kernel_set_to_readonly ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  set_memory_rw (unsigned long,unsigned long) ; 

void set_kernel_text_rw(void)
{
	unsigned long start = PFN_ALIGN(_text);
	unsigned long end = PFN_ALIGN(__stop___ex_table);

	if (!kernel_set_to_readonly)
		return;

	pr_debug("Set kernel text: %lx - %lx for read write\n",
		 start, end);

	/*
	 * Make the kernel identity mapping for text RW. Kernel text
	 * mapping will always be RO. Refer to the comment in
	 * static_protections() in pageattr.c
	 */
	set_memory_rw(start, (end - start) >> PAGE_SHIFT);
}