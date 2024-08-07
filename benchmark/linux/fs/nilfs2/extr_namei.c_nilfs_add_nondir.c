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
 int /*<<< orphan*/  d_instantiate_new (struct dentry*,struct inode*) ; 
 int /*<<< orphan*/  inode_dec_link_count (struct inode*) ; 
 int /*<<< orphan*/  iput (struct inode*) ; 
 int nilfs_add_link (struct dentry*,struct inode*) ; 
 int /*<<< orphan*/  unlock_new_inode (struct inode*) ; 

__attribute__((used)) static inline int nilfs_add_nondir(struct dentry *dentry, struct inode *inode)
{
	int err = nilfs_add_link(dentry, inode);

	if (!err) {
		d_instantiate_new(dentry, inode);
		return 0;
	}
	inode_dec_link_count(inode);
	unlock_new_inode(inode);
	iput(inode);
	return err;
}