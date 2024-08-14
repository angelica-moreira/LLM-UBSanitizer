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
typedef  unsigned long __u64 ;
struct TYPE_2__ {unsigned long mi_first_entry_offset; } ;

/* Variables and functions */
 TYPE_1__* NILFS_MDT (struct inode const*) ; 
 scalar_t__ nilfs_cpfile_checkpoints_per_block (struct inode const*) ; 

__attribute__((used)) static __u64 nilfs_cpfile_first_checkpoint_in_block(const struct inode *cpfile,
						    unsigned long blkoff)
{
	return (__u64)nilfs_cpfile_checkpoints_per_block(cpfile) * blkoff
		+ 1 - NILFS_MDT(cpfile)->mi_first_entry_offset;
}