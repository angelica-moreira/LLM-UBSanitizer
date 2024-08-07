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
struct super_block {struct afs_super_info* s_fs_info; } ;
struct afs_super_info {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline struct afs_super_info *AFS_FS_S(struct super_block *sb)
{
	return sb->s_fs_info;
}