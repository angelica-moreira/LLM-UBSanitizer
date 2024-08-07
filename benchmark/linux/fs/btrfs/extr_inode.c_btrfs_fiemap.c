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
struct fiemap_extent_info {int dummy; } ;
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int /*<<< orphan*/  BTRFS_FIEMAP_FLAGS ; 
 int extent_fiemap (struct inode*,struct fiemap_extent_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int fiemap_check_flags (struct fiemap_extent_info*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int btrfs_fiemap(struct inode *inode, struct fiemap_extent_info *fieinfo,
		__u64 start, __u64 len)
{
	int	ret;

	ret = fiemap_check_flags(fieinfo, BTRFS_FIEMAP_FLAGS);
	if (ret)
		return ret;

	return extent_fiemap(inode, fieinfo, start, len);
}