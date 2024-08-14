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
 int /*<<< orphan*/  ocfs2_free_file_private (struct inode*,struct file*) ; 

__attribute__((used)) static int ocfs2_dir_release(struct inode *inode, struct file *file)
{
	ocfs2_free_file_private(inode, file);
	return 0;
}