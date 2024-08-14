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
struct rb_root {int dummy; } ;
struct pnfs_block_extent {int /*<<< orphan*/  be_device; int /*<<< orphan*/  be_node; scalar_t__ be_length; } ;

/* Variables and functions */
 scalar_t__ ext_can_merge (struct pnfs_block_extent*,struct pnfs_block_extent*) ; 
 struct pnfs_block_extent* ext_tree_next (struct pnfs_block_extent*) ; 
 int /*<<< orphan*/  kfree (struct pnfs_block_extent*) ; 
 int /*<<< orphan*/  nfs4_put_deviceid_node (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rb_erase (int /*<<< orphan*/ *,struct rb_root*) ; 

__attribute__((used)) static struct pnfs_block_extent *
ext_try_to_merge_right(struct rb_root *root, struct pnfs_block_extent *be)
{
	struct pnfs_block_extent *right = ext_tree_next(be);

	if (right && ext_can_merge(be, right)) {
		be->be_length += right->be_length;
		rb_erase(&right->be_node, root);
		nfs4_put_deviceid_node(right->be_device);
		kfree(right);
	}

	return be;
}