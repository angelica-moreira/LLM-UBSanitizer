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
struct the_nilfs {int /*<<< orphan*/  ns_sem; } ;
struct super_block {struct the_nilfs* s_fs_info; } ;

/* Variables and functions */
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int nilfs_cleanup_super (struct super_block*) ; 
 scalar_t__ sb_rdonly (struct super_block*) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int nilfs_freeze(struct super_block *sb)
{
	struct the_nilfs *nilfs = sb->s_fs_info;
	int err;

	if (sb_rdonly(sb))
		return 0;

	/* Mark super block clean */
	down_write(&nilfs->ns_sem);
	err = nilfs_cleanup_super(sb);
	up_write(&nilfs->ns_sem);
	return err;
}