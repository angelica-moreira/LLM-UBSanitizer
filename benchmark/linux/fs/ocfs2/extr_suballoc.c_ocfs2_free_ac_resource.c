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
struct ocfs2_alloc_context {scalar_t__ ac_which; int /*<<< orphan*/ * ac_find_loc_priv; int /*<<< orphan*/ * ac_resv; int /*<<< orphan*/ * ac_bh; struct inode* ac_inode; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 scalar_t__ OCFS2_AC_USE_LOCAL ; 
 int /*<<< orphan*/  brelse (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  inode_unlock (struct inode*) ; 
 int /*<<< orphan*/  iput (struct inode*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ocfs2_inode_unlock (struct inode*,int) ; 

void ocfs2_free_ac_resource(struct ocfs2_alloc_context *ac)
{
	struct inode *inode = ac->ac_inode;

	if (inode) {
		if (ac->ac_which != OCFS2_AC_USE_LOCAL)
			ocfs2_inode_unlock(inode, 1);

		inode_unlock(inode);

		iput(inode);
		ac->ac_inode = NULL;
	}
	brelse(ac->ac_bh);
	ac->ac_bh = NULL;
	ac->ac_resv = NULL;
	kfree(ac->ac_find_loc_priv);
	ac->ac_find_loc_priv = NULL;
}