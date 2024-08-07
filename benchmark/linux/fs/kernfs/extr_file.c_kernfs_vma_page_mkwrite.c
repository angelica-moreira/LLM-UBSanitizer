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
struct vm_fault {TYPE_1__* vma; } ;
struct kernfs_open_file {int /*<<< orphan*/  kn; TYPE_2__* vm_ops; } ;
struct file {int dummy; } ;
struct TYPE_4__ {scalar_t__ (* page_mkwrite ) (struct vm_fault*) ;} ;
struct TYPE_3__ {struct file* vm_file; } ;

/* Variables and functions */
 scalar_t__ VM_FAULT_SIGBUS ; 
 int /*<<< orphan*/  file_update_time (struct file*) ; 
 int /*<<< orphan*/  kernfs_get_active (int /*<<< orphan*/ ) ; 
 struct kernfs_open_file* kernfs_of (struct file*) ; 
 int /*<<< orphan*/  kernfs_put_active (int /*<<< orphan*/ ) ; 
 scalar_t__ stub1 (struct vm_fault*) ; 

__attribute__((used)) static vm_fault_t kernfs_vma_page_mkwrite(struct vm_fault *vmf)
{
	struct file *file = vmf->vma->vm_file;
	struct kernfs_open_file *of = kernfs_of(file);
	vm_fault_t ret;

	if (!of->vm_ops)
		return VM_FAULT_SIGBUS;

	if (!kernfs_get_active(of->kn))
		return VM_FAULT_SIGBUS;

	ret = 0;
	if (of->vm_ops->page_mkwrite)
		ret = of->vm_ops->page_mkwrite(vmf);
	else
		file_update_time(file);

	kernfs_put_active(of->kn);
	return ret;
}