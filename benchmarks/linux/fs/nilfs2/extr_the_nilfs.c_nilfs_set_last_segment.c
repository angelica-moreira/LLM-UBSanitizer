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
typedef  scalar_t__ u64 ;
struct the_nilfs {scalar_t__ ns_last_seq; scalar_t__ ns_prev_seq; int /*<<< orphan*/  ns_last_segment_lock; int /*<<< orphan*/  ns_last_cno; int /*<<< orphan*/  ns_last_pseg; } ;
typedef  int /*<<< orphan*/  sector_t ;
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int /*<<< orphan*/  nilfs_sb_dirty (struct the_nilfs*) ; 
 int /*<<< orphan*/  set_nilfs_sb_dirty (struct the_nilfs*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

void nilfs_set_last_segment(struct the_nilfs *nilfs,
			    sector_t start_blocknr, u64 seq, __u64 cno)
{
	spin_lock(&nilfs->ns_last_segment_lock);
	nilfs->ns_last_pseg = start_blocknr;
	nilfs->ns_last_seq = seq;
	nilfs->ns_last_cno = cno;

	if (!nilfs_sb_dirty(nilfs)) {
		if (nilfs->ns_prev_seq == nilfs->ns_last_seq)
			goto stay_cursor;

		set_nilfs_sb_dirty(nilfs);
	}
	nilfs->ns_prev_seq = nilfs->ns_last_seq;

 stay_cursor:
	spin_unlock(&nilfs->ns_last_segment_lock);
}