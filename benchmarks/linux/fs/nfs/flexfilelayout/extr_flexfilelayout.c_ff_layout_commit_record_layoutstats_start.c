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
struct rpc_task {int /*<<< orphan*/  tk_start; } ;
struct nfs_commit_data {int /*<<< orphan*/  ds_commit_index; int /*<<< orphan*/  lseg; int /*<<< orphan*/  inode; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  FF_LAYOUT_COMP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NFS_IOHDR_STAT ; 
 int /*<<< orphan*/  nfs4_ff_layout_stat_io_start_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ff_layout_commit_record_layoutstats_start(struct rpc_task *task,
		struct nfs_commit_data *cdata)
{
	if (test_and_set_bit(NFS_IOHDR_STAT, &cdata->flags))
		return;
	nfs4_ff_layout_stat_io_start_write(cdata->inode,
			FF_LAYOUT_COMP(cdata->lseg, cdata->ds_commit_index),
			0, task->tk_start);
}