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
 int EOPNOTSUPP ; 
 int __hfsplus_setxattr (struct inode*,char const*,void const*,size_t,int) ; 
 scalar_t__ is_known_namespace (char const*) ; 

__attribute__((used)) static int hfsplus_osx_setxattr(const struct xattr_handler *handler,
				struct dentry *unused, struct inode *inode,
				const char *name, const void *buffer,
				size_t size, int flags)
{
	/*
	 * Don't allow setting properly prefixed attributes
	 * by prepending them with "osx."
	 */
	if (is_known_namespace(name))
		return -EOPNOTSUPP;

	/*
	 * osx is the namespace we use to indicate an unprefixed
	 * attribute on the filesystem (like the ones that OS X
	 * creates), so we pass the name through unmodified (after
	 * ensuring it doesn't conflict with another namespace).
	 */
	return __hfsplus_setxattr(inode, name, buffer, size, flags);
}