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
struct btrfs_root {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTRFS_QGROUP_RSV_META_PREALLOC ; 
 int /*<<< orphan*/  __btrfs_qgroup_free_meta (struct btrfs_root*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void btrfs_qgroup_free_meta_prealloc(struct btrfs_root *root,
						   int num_bytes)
{
	__btrfs_qgroup_free_meta(root, num_bytes,
			BTRFS_QGROUP_RSV_META_PREALLOC);
}