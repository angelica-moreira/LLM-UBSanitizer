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
struct vm_area_struct {int /*<<< orphan*/  vm_mm; } ;
typedef  int /*<<< orphan*/  pte_t ;

/* Variables and functions */
 int /*<<< orphan*/  flush_tlb_fix_spurious_fault (struct vm_area_struct*,unsigned long) ; 
 int /*<<< orphan*/  pte_same (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_pte_at (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int ptep_set_access_flags(struct vm_area_struct *vma,
			  unsigned long address, pte_t *ptep,
			  pte_t entry, int dirty)
{
	int changed = !pte_same(*ptep, entry);
	if (changed) {
		set_pte_at(vma->vm_mm, address, ptep, entry);
		flush_tlb_fix_spurious_fault(vma, address);
	}
	return changed;
}