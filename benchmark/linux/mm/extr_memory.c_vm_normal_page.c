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
struct vm_area_struct {int vm_flags; unsigned long vm_start; unsigned long vm_pgoff; TYPE_1__* vm_ops; } ;
struct page {int dummy; } ;
typedef  int /*<<< orphan*/  pte_t ;
struct TYPE_2__ {struct page* (* find_special_page ) (struct vm_area_struct*,unsigned long) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_ARCH_HAS_PTE_SPECIAL ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 unsigned long PAGE_SHIFT ; 
 int VM_MIXEDMAP ; 
 int VM_PFNMAP ; 
 unsigned long highest_memmap_pfn ; 
 int /*<<< orphan*/  is_cow_mapping (int) ; 
 scalar_t__ is_zero_pfn (unsigned long) ; 
 scalar_t__ likely (int) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pfn_valid (unsigned long) ; 
 int /*<<< orphan*/  print_bad_pte (struct vm_area_struct*,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ pte_devmap (int /*<<< orphan*/ ) ; 
 unsigned long pte_pfn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pte_special (int /*<<< orphan*/ ) ; 
 struct page* stub1 (struct vm_area_struct*,unsigned long) ; 
 scalar_t__ unlikely (int) ; 

struct page *vm_normal_page(struct vm_area_struct *vma, unsigned long addr,
			    pte_t pte)
{
	unsigned long pfn = pte_pfn(pte);

	if (IS_ENABLED(CONFIG_ARCH_HAS_PTE_SPECIAL)) {
		if (likely(!pte_special(pte)))
			goto check_pfn;
		if (vma->vm_ops && vma->vm_ops->find_special_page)
			return vma->vm_ops->find_special_page(vma, addr);
		if (vma->vm_flags & (VM_PFNMAP | VM_MIXEDMAP))
			return NULL;
		if (is_zero_pfn(pfn))
			return NULL;
		if (pte_devmap(pte))
			return NULL;

		print_bad_pte(vma, addr, pte, NULL);
		return NULL;
	}

	/* !CONFIG_ARCH_HAS_PTE_SPECIAL case follows: */

	if (unlikely(vma->vm_flags & (VM_PFNMAP|VM_MIXEDMAP))) {
		if (vma->vm_flags & VM_MIXEDMAP) {
			if (!pfn_valid(pfn))
				return NULL;
			goto out;
		} else {
			unsigned long off;
			off = (addr - vma->vm_start) >> PAGE_SHIFT;
			if (pfn == vma->vm_pgoff + off)
				return NULL;
			if (!is_cow_mapping(vma->vm_flags))
				return NULL;
		}
	}

	if (is_zero_pfn(pfn))
		return NULL;

check_pfn:
	if (unlikely(pfn > highest_memmap_pfn)) {
		print_bad_pte(vma, addr, pte, NULL);
		return NULL;
	}

	/*
	 * NOTE! We still have PageReserved() pages in the page tables.
	 * eg. VDSO mappings can cause them to exist.
	 */
out:
	return pfn_to_page(pfn);
}