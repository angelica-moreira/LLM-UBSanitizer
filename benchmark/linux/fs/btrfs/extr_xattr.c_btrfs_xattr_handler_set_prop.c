#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct xattr_handler {int dummy; } ;
struct inode {int /*<<< orphan*/  i_ctime; } ;
struct dentry {int dummy; } ;
struct btrfs_trans_handle {int dummy; } ;
struct btrfs_root {int dummy; } ;
struct TYPE_2__ {struct btrfs_root* root; } ;

/* Variables and functions */
 TYPE_1__* BTRFS_I (struct inode*) ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 scalar_t__ IS_ERR (struct btrfs_trans_handle*) ; 
 int PTR_ERR (struct btrfs_trans_handle*) ; 
 int /*<<< orphan*/  btrfs_end_transaction (struct btrfs_trans_handle*) ; 
 int btrfs_set_prop (struct btrfs_trans_handle*,struct inode*,char const*,void const*,size_t,int) ; 
 struct btrfs_trans_handle* btrfs_start_transaction (struct btrfs_root*,int) ; 
 int btrfs_update_inode (struct btrfs_trans_handle*,struct btrfs_root*,struct inode*) ; 
 int btrfs_validate_prop (char const*,void const*,size_t) ; 
 int /*<<< orphan*/  current_time (struct inode*) ; 
 int /*<<< orphan*/  inode_inc_iversion (struct inode*) ; 
 char* xattr_full_name (struct xattr_handler const*,char const*) ; 

__attribute__((used)) static int btrfs_xattr_handler_set_prop(const struct xattr_handler *handler,
					struct dentry *unused, struct inode *inode,
					const char *name, const void *value,
					size_t size, int flags)
{
	int ret;
	struct btrfs_trans_handle *trans;
	struct btrfs_root *root = BTRFS_I(inode)->root;

	name = xattr_full_name(handler, name);
	ret = btrfs_validate_prop(name, value, size);
	if (ret)
		return ret;

	trans = btrfs_start_transaction(root, 2);
	if (IS_ERR(trans))
		return PTR_ERR(trans);

	ret = btrfs_set_prop(trans, inode, name, value, size, flags);
	if (!ret) {
		inode_inc_iversion(inode);
		inode->i_ctime = current_time(inode);
		ret = btrfs_update_inode(trans, root, inode);
		BUG_ON(ret);
	}

	btrfs_end_transaction(trans);

	return ret;
}