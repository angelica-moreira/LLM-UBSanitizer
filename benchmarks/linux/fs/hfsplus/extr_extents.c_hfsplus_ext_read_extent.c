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
typedef  scalar_t__ u32 ;
struct inode {int /*<<< orphan*/  i_sb; } ;
struct hfsplus_inode_info {scalar_t__ cached_start; scalar_t__ cached_blocks; } ;
struct hfs_find_data {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  ext_tree; } ;

/* Variables and functions */
 struct hfsplus_inode_info* HFSPLUS_I (struct inode*) ; 
 TYPE_1__* HFSPLUS_SB (int /*<<< orphan*/ ) ; 
 int __hfsplus_ext_cache_extent (struct hfs_find_data*,struct inode*,scalar_t__) ; 
 int /*<<< orphan*/  hfs_find_exit (struct hfs_find_data*) ; 
 int hfs_find_init (int /*<<< orphan*/ ,struct hfs_find_data*) ; 

__attribute__((used)) static int hfsplus_ext_read_extent(struct inode *inode, u32 block)
{
	struct hfsplus_inode_info *hip = HFSPLUS_I(inode);
	struct hfs_find_data fd;
	int res;

	if (block >= hip->cached_start &&
	    block < hip->cached_start + hip->cached_blocks)
		return 0;

	res = hfs_find_init(HFSPLUS_SB(inode->i_sb)->ext_tree, &fd);
	if (!res) {
		res = __hfsplus_ext_cache_extent(&fd, inode, block);
		hfs_find_exit(&fd);
	}
	return res;
}