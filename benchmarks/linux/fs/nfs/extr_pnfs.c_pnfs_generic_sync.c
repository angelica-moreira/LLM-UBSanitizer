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
struct inode {int dummy; } ;

/* Variables and functions */
 int pnfs_layoutcommit_inode (struct inode*,int) ; 

int
pnfs_generic_sync(struct inode *inode, bool datasync)
{
	return pnfs_layoutcommit_inode(inode, true);
}