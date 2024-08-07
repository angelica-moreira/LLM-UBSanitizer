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
struct xattr_handler {int dummy; } ;
struct inode {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int orangefs_inode_setxattr (struct inode*,char const*,void const*,size_t,int) ; 

__attribute__((used)) static int orangefs_xattr_set_default(const struct xattr_handler *handler,
				      struct dentry *unused,
				      struct inode *inode,
				      const char *name,
				      const void *buffer,
				      size_t size,
				      int flags)
{
	return orangefs_inode_setxattr(inode, name, buffer, size, flags);
}