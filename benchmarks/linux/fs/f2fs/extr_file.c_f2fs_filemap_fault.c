#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ vm_fault_t ;
struct vm_fault {int /*<<< orphan*/  pgoff; TYPE_1__* vma; } ;
struct inode {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  i_mmap_sem; } ;
struct TYPE_3__ {int /*<<< orphan*/  vm_file; } ;

/* Variables and functions */
 TYPE_2__* F2FS_I (struct inode*) ; 
 int /*<<< orphan*/  down_read (int /*<<< orphan*/ *) ; 
 struct inode* file_inode (int /*<<< orphan*/ ) ; 
 scalar_t__ filemap_fault (struct vm_fault*) ; 
 int /*<<< orphan*/  trace_f2fs_filemap_fault (struct inode*,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static vm_fault_t f2fs_filemap_fault(struct vm_fault *vmf)
{
	struct inode *inode = file_inode(vmf->vma->vm_file);
	vm_fault_t ret;

	down_read(&F2FS_I(inode)->i_mmap_sem);
	ret = filemap_fault(vmf);
	up_read(&F2FS_I(inode)->i_mmap_sem);

	trace_f2fs_filemap_fault(inode, vmf->pgoff, (unsigned long)ret);

	return ret;
}