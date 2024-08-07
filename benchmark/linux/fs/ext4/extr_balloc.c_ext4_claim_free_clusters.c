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
struct ext4_sb_info {int /*<<< orphan*/  s_dirtyclusters_counter; } ;
typedef  int /*<<< orphan*/  s64 ;

/* Variables and functions */
 int ENOSPC ; 
 scalar_t__ ext4_has_free_clusters (struct ext4_sb_info*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  percpu_counter_add (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int ext4_claim_free_clusters(struct ext4_sb_info *sbi,
			     s64 nclusters, unsigned int flags)
{
	if (ext4_has_free_clusters(sbi, nclusters, flags)) {
		percpu_counter_add(&sbi->s_dirtyclusters_counter, nclusters);
		return 0;
	} else
		return -ENOSPC;
}