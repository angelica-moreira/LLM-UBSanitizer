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
 int /*<<< orphan*/  EXT4_XATTR_INDEX_SECURITY ; 
 int ext4_xattr_get (struct inode*,int /*<<< orphan*/ ,char const*,void*,size_t) ; 

__attribute__((used)) static int
ext4_xattr_security_get(const struct xattr_handler *handler,
			struct dentry *unused, struct inode *inode,
			const char *name, void *buffer, size_t size)
{
	return ext4_xattr_get(inode, EXT4_XATTR_INDEX_SECURITY,
			      name, buffer, size);
}