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
struct xfs_inode {int dummy; } ;
struct xattr_handler {int flags; } ;
struct inode {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int ATTR_KERNOVAL ; 
 struct xfs_inode* XFS_I (struct inode*) ; 
 int xfs_attr_get (struct xfs_inode*,char const*,unsigned char**,int*,int) ; 

__attribute__((used)) static int
xfs_xattr_get(const struct xattr_handler *handler, struct dentry *unused,
		struct inode *inode, const char *name, void *value, size_t size)
{
	int xflags = handler->flags;
	struct xfs_inode *ip = XFS_I(inode);
	int error, asize = size;

	/* Convert Linux syscall to XFS internal ATTR flags */
	if (!size) {
		xflags |= ATTR_KERNOVAL;
		value = NULL;
	}

	error = xfs_attr_get(ip, name, (unsigned char **)&value, &asize, xflags);
	if (error)
		return error;
	return asize;
}