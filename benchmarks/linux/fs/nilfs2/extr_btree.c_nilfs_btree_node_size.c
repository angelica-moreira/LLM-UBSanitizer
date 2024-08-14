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
struct nilfs_bmap {int /*<<< orphan*/  b_inode; } ;

/* Variables and functions */
 int i_blocksize (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nilfs_btree_node_size(const struct nilfs_bmap *btree)
{
	return i_blocksize(btree->b_inode);
}