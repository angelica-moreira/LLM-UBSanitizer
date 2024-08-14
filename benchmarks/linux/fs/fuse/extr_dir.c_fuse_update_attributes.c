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
 int STATX_ATIME ; 
 int STATX_BASIC_STATS ; 
 int fuse_update_get_attr (struct inode*,struct file*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

int fuse_update_attributes(struct inode *inode, struct file *file)
{
	/* Do *not* need to get atime for internal purposes */
	return fuse_update_get_attr(inode, file, NULL,
				    STATX_BASIC_STATS & ~STATX_ATIME, 0);
}