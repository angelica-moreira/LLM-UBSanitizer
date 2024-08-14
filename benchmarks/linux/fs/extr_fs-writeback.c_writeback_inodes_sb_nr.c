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
typedef  enum wb_reason { ____Placeholder_wb_reason } wb_reason ;

/* Variables and functions */
 int /*<<< orphan*/  __writeback_inodes_sb_nr (struct super_block*,unsigned long,int,int) ; 

void writeback_inodes_sb_nr(struct super_block *sb,
			    unsigned long nr,
			    enum wb_reason reason)
{
	__writeback_inodes_sb_nr(sb, nr, reason, false);
}