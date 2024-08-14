#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
struct scrub_block {int page_count; TYPE_1__** pagev; scalar_t__ checksum_error; scalar_t__ generation_error; scalar_t__ header_error; } ;
struct TYPE_2__ {int flags; } ;

/* Variables and functions */
 int BTRFS_EXTENT_FLAG_DATA ; 
 int BTRFS_EXTENT_FLAG_SUPER ; 
 int BTRFS_EXTENT_FLAG_TREE_BLOCK ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int scrub_checksum_data (struct scrub_block*) ; 
 int /*<<< orphan*/  scrub_checksum_super (struct scrub_block*) ; 
 int scrub_checksum_tree_block (struct scrub_block*) ; 
 int /*<<< orphan*/  scrub_handle_errored_block (struct scrub_block*) ; 

__attribute__((used)) static int scrub_checksum(struct scrub_block *sblock)
{
	u64 flags;
	int ret;

	/*
	 * No need to initialize these stats currently,
	 * because this function only use return value
	 * instead of these stats value.
	 *
	 * Todo:
	 * always use stats
	 */
	sblock->header_error = 0;
	sblock->generation_error = 0;
	sblock->checksum_error = 0;

	WARN_ON(sblock->page_count < 1);
	flags = sblock->pagev[0]->flags;
	ret = 0;
	if (flags & BTRFS_EXTENT_FLAG_DATA)
		ret = scrub_checksum_data(sblock);
	else if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK)
		ret = scrub_checksum_tree_block(sblock);
	else if (flags & BTRFS_EXTENT_FLAG_SUPER)
		(void)scrub_checksum_super(sblock);
	else
		WARN_ON(1);
	if (ret)
		scrub_handle_errored_block(sblock);

	return ret;
}