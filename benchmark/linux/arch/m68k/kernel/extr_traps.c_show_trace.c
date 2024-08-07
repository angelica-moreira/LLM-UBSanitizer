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
 unsigned long THREAD_SIZE ; 
 scalar_t__ __kernel_text_address (unsigned long) ; 
 int /*<<< orphan*/  pr_cont (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*) ; 

void show_trace(unsigned long *stack)
{
	unsigned long *endstack;
	unsigned long addr;
	int i;

	pr_info("Call Trace:");
	addr = (unsigned long)stack + THREAD_SIZE - 1;
	endstack = (unsigned long *)(addr & -THREAD_SIZE);
	i = 0;
	while (stack + 1 <= endstack) {
		addr = *stack++;
		/*
		 * If the address is either in the text segment of the
		 * kernel, or in the region which contains vmalloc'ed
		 * memory, it *may* be the address of a calling
		 * routine; if so, print it so that someone tracing
		 * down the cause of the crash will be able to figure
		 * out the call path that was taken.
		 */
		if (__kernel_text_address(addr)) {
#ifndef CONFIG_KALLSYMS
			if (i % 5 == 0)
				pr_cont("\n       ");
#endif
			pr_cont(" [<%08lx>] %pS\n", addr, (void *)addr);
			i++;
		}
	}
	pr_cont("\n");
}