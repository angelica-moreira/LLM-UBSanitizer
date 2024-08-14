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
struct ocfs2_inode_info {int /*<<< orphan*/  ip_blkno; } ;
struct ocfs2_caching_info {int dummy; } ;

/* Variables and functions */
 struct ocfs2_inode_info* cache_info_to_inode (struct ocfs2_caching_info*) ; 

__attribute__((used)) static u64 ocfs2_inode_cache_owner(struct ocfs2_caching_info *ci)
{
	struct ocfs2_inode_info *oi = cache_info_to_inode(ci);

	return oi->ip_blkno;
}