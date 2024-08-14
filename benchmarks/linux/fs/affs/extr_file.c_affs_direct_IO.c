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
struct kiocb {scalar_t__ ki_pos; struct file* ki_filp; } ;
struct iov_iter {int dummy; } ;
struct inode {int dummy; } ;
struct file {struct address_space* f_mapping; } ;
struct address_space {struct inode* host; } ;
typedef  scalar_t__ ssize_t ;
typedef  scalar_t__ loff_t ;
struct TYPE_2__ {scalar_t__ mmu_private; } ;

/* Variables and functions */
 TYPE_1__* AFFS_I (struct inode*) ; 
 scalar_t__ WRITE ; 
 int /*<<< orphan*/  affs_get_block ; 
 int /*<<< orphan*/  affs_write_failed (struct address_space*,scalar_t__) ; 
 scalar_t__ blockdev_direct_IO (struct kiocb*,struct inode*,struct iov_iter*,int /*<<< orphan*/ ) ; 
 size_t iov_iter_count (struct iov_iter*) ; 
 scalar_t__ iov_iter_rw (struct iov_iter*) ; 

__attribute__((used)) static ssize_t
affs_direct_IO(struct kiocb *iocb, struct iov_iter *iter)
{
	struct file *file = iocb->ki_filp;
	struct address_space *mapping = file->f_mapping;
	struct inode *inode = mapping->host;
	size_t count = iov_iter_count(iter);
	loff_t offset = iocb->ki_pos;
	ssize_t ret;

	if (iov_iter_rw(iter) == WRITE) {
		loff_t size = offset + count;

		if (AFFS_I(inode)->mmu_private < size)
			return 0;
	}

	ret = blockdev_direct_IO(iocb, inode, iter, affs_get_block);
	if (ret < 0 && iov_iter_rw(iter) == WRITE)
		affs_write_failed(mapping, offset + count);
	return ret;
}