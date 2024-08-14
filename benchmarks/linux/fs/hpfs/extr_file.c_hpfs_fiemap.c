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
struct inode {int dummy; } ;
struct fiemap_extent_info {int dummy; } ;

/* Variables and functions */
 int generic_block_fiemap (struct inode*,struct fiemap_extent_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hpfs_get_block ; 

__attribute__((used)) static int hpfs_fiemap(struct inode *inode, struct fiemap_extent_info *fieinfo, u64 start, u64 len)
{
	return generic_block_fiemap(inode, fieinfo, start, len, hpfs_get_block);
}