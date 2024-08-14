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
struct dentry {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  XATTR_NAME_CAPS ; 
 int __vfs_removexattr (struct dentry*,int /*<<< orphan*/ ) ; 

int cap_inode_killpriv(struct dentry *dentry)
{
	int error;

	error = __vfs_removexattr(dentry, XATTR_NAME_CAPS);
	if (error == -EOPNOTSUPP)
		error = 0;
	return error;
}