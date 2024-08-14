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
 int /*<<< orphan*/  pr_info (char*,unsigned long,char*,void*) ; 

__attribute__((used)) static void _print_addr(void *data, unsigned long address, int reliable)
{
	pr_info(" [<%08lx>] %s%pS\n", address, reliable ? "" : "? ",
		(void *)address);
}