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
struct TYPE_2__ {int /*<<< orphan*/  rpcs_out; int /*<<< orphan*/  ncommit; int /*<<< orphan*/  list; } ;
struct nfs_inode {int /*<<< orphan*/  commit_mutex; int /*<<< orphan*/  rmdir_sem; TYPE_1__ commit_info; int /*<<< orphan*/  nrequests; int /*<<< orphan*/  access_cache_inode_lru; int /*<<< orphan*/  access_cache_entry_lru; int /*<<< orphan*/  open_files; int /*<<< orphan*/  vfs_inode; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_long_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_rwsem (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  inode_init_once (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nfs4_init_once (struct nfs_inode*) ; 

__attribute__((used)) static void init_once(void *foo)
{
	struct nfs_inode *nfsi = (struct nfs_inode *) foo;

	inode_init_once(&nfsi->vfs_inode);
	INIT_LIST_HEAD(&nfsi->open_files);
	INIT_LIST_HEAD(&nfsi->access_cache_entry_lru);
	INIT_LIST_HEAD(&nfsi->access_cache_inode_lru);
	INIT_LIST_HEAD(&nfsi->commit_info.list);
	atomic_long_set(&nfsi->nrequests, 0);
	atomic_long_set(&nfsi->commit_info.ncommit, 0);
	atomic_set(&nfsi->commit_info.rpcs_out, 0);
	init_rwsem(&nfsi->rmdir_sem);
	mutex_init(&nfsi->commit_mutex);
	nfs4_init_once(nfsi);
}