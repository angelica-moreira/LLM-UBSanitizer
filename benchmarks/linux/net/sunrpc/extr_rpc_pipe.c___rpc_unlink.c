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
 int /*<<< orphan*/  d_delete (struct dentry*) ; 
 int /*<<< orphan*/  dget (struct dentry*) ; 
 int /*<<< orphan*/  dput (struct dentry*) ; 
 int /*<<< orphan*/  fsnotify_unlink (struct inode*,struct dentry*) ; 
 int simple_unlink (struct inode*,struct dentry*) ; 

__attribute__((used)) static int __rpc_unlink(struct inode *dir, struct dentry *dentry)
{
	int ret;

	dget(dentry);
	ret = simple_unlink(dir, dentry);
	if (!ret)
		fsnotify_unlink(dir, dentry);
	d_delete(dentry);
	dput(dentry);
	return ret;
}