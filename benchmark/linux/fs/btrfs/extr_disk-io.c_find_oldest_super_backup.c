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
typedef  int /*<<< orphan*/  u64 ;
struct btrfs_fs_info {int backup_root_index; } ;

/* Variables and functions */
 int BTRFS_NUM_BACKUP_ROOTS ; 
 int find_newest_super_backup (struct btrfs_fs_info*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void find_oldest_super_backup(struct btrfs_fs_info *info,
				     u64 newest_gen)
{
	int newest_index = -1;

	newest_index = find_newest_super_backup(info, newest_gen);
	/* if there was garbage in there, just move along */
	if (newest_index == -1) {
		info->backup_root_index = 0;
	} else {
		info->backup_root_index = (newest_index + 1) % BTRFS_NUM_BACKUP_ROOTS;
	}
}