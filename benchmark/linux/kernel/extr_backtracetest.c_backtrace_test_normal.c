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
 int /*<<< orphan*/  dump_stack () ; 
 int /*<<< orphan*/  pr_info (char*) ; 

__attribute__((used)) static void backtrace_test_normal(void)
{
	pr_info("Testing a backtrace from process context.\n");
	pr_info("The following trace is a kernel self test and not a bug!\n");

	dump_stack();
}