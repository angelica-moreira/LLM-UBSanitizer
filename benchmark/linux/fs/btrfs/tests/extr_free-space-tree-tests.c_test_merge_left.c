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
typedef  int u32 ;
struct free_space_extent {int member_0; int member_1; } ;
struct btrfs_trans_handle {int dummy; } ;
struct btrfs_path {int dummy; } ;
struct btrfs_fs_info {int dummy; } ;
struct TYPE_2__ {int objectid; int /*<<< orphan*/  offset; } ;
struct btrfs_block_group_cache {TYPE_1__ key; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (struct free_space_extent const*) ; 
 int __add_to_free_space_tree (struct btrfs_trans_handle*,struct btrfs_block_group_cache*,struct btrfs_path*,int,int) ; 
 int __remove_from_free_space_tree (struct btrfs_trans_handle*,struct btrfs_block_group_cache*,struct btrfs_path*,int,int /*<<< orphan*/ ) ; 
 int check_free_space_extents (struct btrfs_trans_handle*,struct btrfs_fs_info*,struct btrfs_block_group_cache*,struct btrfs_path*,struct free_space_extent const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_err (char*) ; 

__attribute__((used)) static int test_merge_left(struct btrfs_trans_handle *trans,
			   struct btrfs_fs_info *fs_info,
			   struct btrfs_block_group_cache *cache,
			   struct btrfs_path *path,
			   u32 alignment)
{
	const struct free_space_extent extents[] = {
		{cache->key.objectid, 2 * alignment},
	};
	int ret;

	ret = __remove_from_free_space_tree(trans, cache, path,
					    cache->key.objectid,
					    cache->key.offset);
	if (ret) {
		test_err("could not remove free space");
		return ret;
	}

	ret = __add_to_free_space_tree(trans, cache, path, cache->key.objectid,
				       alignment);
	if (ret) {
		test_err("could not add free space");
		return ret;
	}

	ret = __add_to_free_space_tree(trans, cache, path,
				       cache->key.objectid + alignment,
				       alignment);
	if (ret) {
		test_err("could not add free space");
		return ret;
	}

	return check_free_space_extents(trans, fs_info, cache, path,
					extents, ARRAY_SIZE(extents));
}