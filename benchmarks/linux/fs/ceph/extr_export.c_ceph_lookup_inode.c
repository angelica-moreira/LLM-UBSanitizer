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
typedef  int /*<<< orphan*/  u64 ;
struct super_block {int dummy; } ;
struct inode {scalar_t__ i_nlink; } ;

/* Variables and functions */
 struct inode* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ESTALE ; 
 scalar_t__ IS_ERR (struct inode*) ; 
 struct inode* __lookup_inode (struct super_block*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iput (struct inode*) ; 

struct inode *ceph_lookup_inode(struct super_block *sb, u64 ino)
{
	struct inode *inode = __lookup_inode(sb, ino);
	if (IS_ERR(inode))
		return inode;
	if (inode->i_nlink == 0) {
		iput(inode);
		return ERR_PTR(-ESTALE);
	}
	return inode;
}