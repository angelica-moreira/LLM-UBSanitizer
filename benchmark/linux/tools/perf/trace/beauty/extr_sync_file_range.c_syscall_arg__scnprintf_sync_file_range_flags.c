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
struct syscall_arg {unsigned long val; int /*<<< orphan*/  show_string_prefix; } ;

/* Variables and functions */
 size_t sync_file_range__scnprintf_flags (unsigned long,char*,size_t,int /*<<< orphan*/ ) ; 

size_t syscall_arg__scnprintf_sync_file_range_flags(char *bf, size_t size, struct syscall_arg *arg)
{
	unsigned long flags = arg->val;

	return sync_file_range__scnprintf_flags(flags, bf, size, arg->show_string_prefix);
}