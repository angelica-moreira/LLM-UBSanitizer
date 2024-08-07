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
 int v9fs_xattr_set (struct dentry*,char const*,void const*,size_t,int) ; 
 char* xattr_full_name (struct xattr_handler const*,char const*) ; 

__attribute__((used)) static int v9fs_xattr_handler_set(const struct xattr_handler *handler,
				  struct dentry *dentry, struct inode *inode,
				  const char *name, const void *value,
				  size_t size, int flags)
{
	const char *full_name = xattr_full_name(handler, name);

	return v9fs_xattr_set(dentry, full_name, value, size, flags);
}