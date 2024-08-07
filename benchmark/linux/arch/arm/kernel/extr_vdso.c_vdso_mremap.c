#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct vm_special_mapping {int dummy; } ;
struct vm_area_struct {unsigned long vm_end; unsigned long vm_start; } ;
struct TYPE_6__ {TYPE_2__* mm; } ;
struct TYPE_4__ {unsigned long vdso; } ;
struct TYPE_5__ {TYPE_1__ context; } ;

/* Variables and functions */
 int EINVAL ; 
 int PAGE_SHIFT ; 
 TYPE_3__* current ; 
 int vdso_total_pages ; 

__attribute__((used)) static int vdso_mremap(const struct vm_special_mapping *sm,
		struct vm_area_struct *new_vma)
{
	unsigned long new_size = new_vma->vm_end - new_vma->vm_start;
	unsigned long vdso_size;

	/* without VVAR page */
	vdso_size = (vdso_total_pages - 1) << PAGE_SHIFT;

	if (vdso_size != new_size)
		return -EINVAL;

	current->mm->context.vdso = new_vma->vm_start;

	return 0;
}