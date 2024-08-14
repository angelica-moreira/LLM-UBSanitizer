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
struct inode {int dummy; } ;
struct dentry {int dummy; } ;
struct TYPE_2__ {int ip_flags; int /*<<< orphan*/  ip_lock; scalar_t__ ip_blkno; } ;

/* Variables and functions */
 int ENOENT ; 
 TYPE_1__* OCFS2_I (struct inode*) ; 
 int OCFS2_INODE_DELETED ; 
 struct inode* d_inode (struct dentry*) ; 
 int /*<<< orphan*/  mlog_errno (int) ; 
 int ocfs2_inode_lock (struct inode*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocfs2_inode_unlock (struct inode*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_ocfs2_inode_revalidate (struct inode*,unsigned long long,unsigned long long) ; 

int ocfs2_inode_revalidate(struct dentry *dentry)
{
	struct inode *inode = d_inode(dentry);
	int status = 0;

	trace_ocfs2_inode_revalidate(inode,
		inode ? (unsigned long long)OCFS2_I(inode)->ip_blkno : 0ULL,
		inode ? (unsigned long long)OCFS2_I(inode)->ip_flags : 0);

	if (!inode) {
		status = -ENOENT;
		goto bail;
	}

	spin_lock(&OCFS2_I(inode)->ip_lock);
	if (OCFS2_I(inode)->ip_flags & OCFS2_INODE_DELETED) {
		spin_unlock(&OCFS2_I(inode)->ip_lock);
		status = -ENOENT;
		goto bail;
	}
	spin_unlock(&OCFS2_I(inode)->ip_lock);

	/* Let ocfs2_inode_lock do the work of updating our struct
	 * inode for us. */
	status = ocfs2_inode_lock(inode, NULL, 0);
	if (status < 0) {
		if (status != -ENOENT)
			mlog_errno(status);
		goto bail;
	}
	ocfs2_inode_unlock(inode, 0);
bail:
	return status;
}