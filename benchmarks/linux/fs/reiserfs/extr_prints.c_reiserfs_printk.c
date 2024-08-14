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
 int /*<<< orphan*/  do_reiserfs_warning (char const*) ; 
 int /*<<< orphan*/  error_buf ; 
 int /*<<< orphan*/  printk (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void reiserfs_printk(const char *fmt, ...)
{
	do_reiserfs_warning(fmt);
	printk(error_buf);
}