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
struct btrfs_trans_handle {int dummy; } ;

/* Variables and functions */
 int inherit_props (struct btrfs_trans_handle*,struct inode*,struct inode*) ; 

int btrfs_inode_inherit_props(struct btrfs_trans_handle *trans,
			      struct inode *inode,
			      struct inode *dir)
{
	if (!dir)
		return 0;

	return inherit_props(trans, inode, dir);
}