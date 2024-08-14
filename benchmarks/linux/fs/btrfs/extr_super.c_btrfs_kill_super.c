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
struct super_block {int dummy; } ;
struct btrfs_fs_info {int dummy; } ;

/* Variables and functions */
 struct btrfs_fs_info* btrfs_sb (struct super_block*) ; 
 int /*<<< orphan*/  free_fs_info (struct btrfs_fs_info*) ; 
 int /*<<< orphan*/  kill_anon_super (struct super_block*) ; 

__attribute__((used)) static void btrfs_kill_super(struct super_block *sb)
{
	struct btrfs_fs_info *fs_info = btrfs_sb(sb);
	kill_anon_super(sb);
	free_fs_info(fs_info);
}