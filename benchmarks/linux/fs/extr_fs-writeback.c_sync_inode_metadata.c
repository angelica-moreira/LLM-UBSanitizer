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
struct writeback_control {int /*<<< orphan*/  nr_to_write; int /*<<< orphan*/  sync_mode; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WB_SYNC_ALL ; 
 int /*<<< orphan*/  WB_SYNC_NONE ; 
 int sync_inode (struct inode*,struct writeback_control*) ; 

int sync_inode_metadata(struct inode *inode, int wait)
{
	struct writeback_control wbc = {
		.sync_mode = wait ? WB_SYNC_ALL : WB_SYNC_NONE,
		.nr_to_write = 0, /* metadata-only */
	};

	return sync_inode(inode, &wbc);
}