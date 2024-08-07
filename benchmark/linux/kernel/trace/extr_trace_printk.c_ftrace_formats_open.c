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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOCKDOWN_TRACEFS ; 
 int security_locked_down (int /*<<< orphan*/ ) ; 
 int seq_open (struct file*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  show_format_seq_ops ; 

__attribute__((used)) static int
ftrace_formats_open(struct inode *inode, struct file *file)
{
	int ret;

	ret = security_locked_down(LOCKDOWN_TRACEFS);
	if (ret)
		return ret;

	return seq_open(file, &show_format_seq_ops);
}