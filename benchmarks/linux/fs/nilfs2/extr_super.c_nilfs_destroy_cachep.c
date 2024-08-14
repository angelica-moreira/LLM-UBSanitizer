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

/* Variables and functions */
 int /*<<< orphan*/  kmem_cache_destroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nilfs_btree_path_cache ; 
 int /*<<< orphan*/  nilfs_inode_cachep ; 
 int /*<<< orphan*/  nilfs_segbuf_cachep ; 
 int /*<<< orphan*/  nilfs_transaction_cachep ; 
 int /*<<< orphan*/  rcu_barrier () ; 

__attribute__((used)) static void nilfs_destroy_cachep(void)
{
	/*
	 * Make sure all delayed rcu free inodes are flushed before we
	 * destroy cache.
	 */
	rcu_barrier();

	kmem_cache_destroy(nilfs_inode_cachep);
	kmem_cache_destroy(nilfs_transaction_cachep);
	kmem_cache_destroy(nilfs_segbuf_cachep);
	kmem_cache_destroy(nilfs_btree_path_cache);
}