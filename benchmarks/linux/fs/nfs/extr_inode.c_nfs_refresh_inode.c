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
struct nfs_fattr {int valid; } ;
struct inode {int /*<<< orphan*/  i_lock; } ;

/* Variables and functions */
 int NFS_ATTR_FATTR ; 
 int nfs_refresh_inode_locked (struct inode*,struct nfs_fattr*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

int nfs_refresh_inode(struct inode *inode, struct nfs_fattr *fattr)
{
	int status;

	if ((fattr->valid & NFS_ATTR_FATTR) == 0)
		return 0;
	spin_lock(&inode->i_lock);
	status = nfs_refresh_inode_locked(inode, fattr);
	spin_unlock(&inode->i_lock);

	return status;
}