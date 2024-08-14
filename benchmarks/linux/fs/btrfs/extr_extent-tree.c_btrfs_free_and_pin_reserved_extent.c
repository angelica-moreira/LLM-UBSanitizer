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
struct btrfs_fs_info {int dummy; } ;

/* Variables and functions */
 int __btrfs_free_reserved_extent (struct btrfs_fs_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

int btrfs_free_and_pin_reserved_extent(struct btrfs_fs_info *fs_info,
				       u64 start, u64 len)
{
	return __btrfs_free_reserved_extent(fs_info, start, len, 1, 0);
}