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
struct btrfs_fs_info {int /*<<< orphan*/  fs_state; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTRFS_FS_STATE_REMOUNTING ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void btrfs_remount_prepare(struct btrfs_fs_info *fs_info)
{
	set_bit(BTRFS_FS_STATE_REMOUNTING, &fs_info->fs_state);
}