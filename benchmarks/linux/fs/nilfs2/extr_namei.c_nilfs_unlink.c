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
struct nilfs_transaction_info {int dummy; } ;
struct inode {int /*<<< orphan*/  i_sb; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 struct inode* d_inode (struct dentry*) ; 
 int nilfs_do_unlink (struct inode*,struct dentry*) ; 
 int /*<<< orphan*/  nilfs_mark_inode_dirty (struct inode*) ; 
 int /*<<< orphan*/  nilfs_transaction_abort (int /*<<< orphan*/ ) ; 
 int nilfs_transaction_begin (int /*<<< orphan*/ ,struct nilfs_transaction_info*,int /*<<< orphan*/ ) ; 
 int nilfs_transaction_commit (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nilfs_unlink(struct inode *dir, struct dentry *dentry)
{
	struct nilfs_transaction_info ti;
	int err;

	err = nilfs_transaction_begin(dir->i_sb, &ti, 0);
	if (err)
		return err;

	err = nilfs_do_unlink(dir, dentry);

	if (!err) {
		nilfs_mark_inode_dirty(dir);
		nilfs_mark_inode_dirty(d_inode(dentry));
		err = nilfs_transaction_commit(dir->i_sb);
	} else
		nilfs_transaction_abort(dir->i_sb);

	return err;
}