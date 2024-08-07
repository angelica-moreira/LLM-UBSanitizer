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
typedef  int /*<<< orphan*/  u64 ;
struct btrfs_trans_handle {TYPE_1__* transaction; } ;
struct btrfs_delayed_ref_root {int /*<<< orphan*/  qgroup_to_skip; } ;
struct TYPE_2__ {struct btrfs_delayed_ref_root delayed_refs; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void btrfs_set_skip_qgroup(struct btrfs_trans_handle *trans,
					 u64 qgroupid)
{
	struct btrfs_delayed_ref_root *delayed_refs;

	delayed_refs = &trans->transaction->delayed_refs;
	WARN_ON(delayed_refs->qgroup_to_skip);
	delayed_refs->qgroup_to_skip = qgroupid;
}