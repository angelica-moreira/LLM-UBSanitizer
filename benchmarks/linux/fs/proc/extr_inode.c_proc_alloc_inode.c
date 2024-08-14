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
struct super_block {int dummy; } ;
struct inode {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/ * proc_get_link; } ;
struct proc_inode {struct inode vfs_inode; int /*<<< orphan*/ * ns_ops; int /*<<< orphan*/ * sysctl_entry; int /*<<< orphan*/ * sysctl; int /*<<< orphan*/ * pde; TYPE_1__ op; scalar_t__ fd; int /*<<< orphan*/ * pid; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct proc_inode* kmem_cache_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  proc_inode_cachep ; 

__attribute__((used)) static struct inode *proc_alloc_inode(struct super_block *sb)
{
	struct proc_inode *ei;

	ei = kmem_cache_alloc(proc_inode_cachep, GFP_KERNEL);
	if (!ei)
		return NULL;
	ei->pid = NULL;
	ei->fd = 0;
	ei->op.proc_get_link = NULL;
	ei->pde = NULL;
	ei->sysctl = NULL;
	ei->sysctl_entry = NULL;
	ei->ns_ops = NULL;
	return &ei->vfs_inode;
}