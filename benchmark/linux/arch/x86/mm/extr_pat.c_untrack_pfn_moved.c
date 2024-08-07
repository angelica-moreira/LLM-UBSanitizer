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
struct vm_area_struct {int /*<<< orphan*/  vm_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  VM_PAT ; 

void untrack_pfn_moved(struct vm_area_struct *vma)
{
	vma->vm_flags &= ~VM_PAT;
}