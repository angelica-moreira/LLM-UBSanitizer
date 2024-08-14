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
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pr_debug (char*,struct dentry*,int) ; 
 int vfs_whiteout (struct inode*,struct dentry*) ; 

__attribute__((used)) static inline int ovl_do_whiteout(struct inode *dir, struct dentry *dentry)
{
	int err = vfs_whiteout(dir, dentry);
	pr_debug("whiteout(%pd2) = %i\n", dentry, err);
	return err;
}