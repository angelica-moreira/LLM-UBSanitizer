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
struct writeback_control {int nr_to_write; int /*<<< orphan*/  range_end; int /*<<< orphan*/  range_start; int /*<<< orphan*/  sync_mode; } ;
struct address_space {int nrpages; } ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 int /*<<< orphan*/  WB_SYNC_ALL ; 
 int generic_writepages (struct address_space*,struct writeback_control*) ; 

__attribute__((used)) static int journal_submit_inode_data_buffers(struct address_space *mapping,
		loff_t dirty_start, loff_t dirty_end)
{
	int ret;
	struct writeback_control wbc = {
		.sync_mode =  WB_SYNC_ALL,
		.nr_to_write = mapping->nrpages * 2,
		.range_start = dirty_start,
		.range_end = dirty_end,
	};

	ret = generic_writepages(mapping, &wbc);
	return ret;
}