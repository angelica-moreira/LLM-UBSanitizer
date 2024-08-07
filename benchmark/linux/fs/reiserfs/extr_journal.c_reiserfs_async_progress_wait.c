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
struct reiserfs_journal {int /*<<< orphan*/  j_async_throttle; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLK_RW_ASYNC ; 
 int HZ ; 
 struct reiserfs_journal* SB_JOURNAL (struct super_block*) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  congestion_wait (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  reiserfs_write_lock_nested (struct super_block*,int) ; 
 int reiserfs_write_unlock_nested (struct super_block*) ; 

__attribute__((used)) static int reiserfs_async_progress_wait(struct super_block *s)
{
	struct reiserfs_journal *j = SB_JOURNAL(s);

	if (atomic_read(&j->j_async_throttle)) {
		int depth;

		depth = reiserfs_write_unlock_nested(s);
		congestion_wait(BLK_RW_ASYNC, HZ / 10);
		reiserfs_write_lock_nested(s, depth);
	}

	return 0;
}