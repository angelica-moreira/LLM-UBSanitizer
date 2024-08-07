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
struct vm_area_struct {int /*<<< orphan*/  vm_page_prot; } ;
struct page {int dummy; } ;
typedef  int /*<<< orphan*/  pte_t ;

/* Variables and functions */
 int /*<<< orphan*/  arch_make_huge_pte (int /*<<< orphan*/ ,struct vm_area_struct*,struct page*,int) ; 
 int /*<<< orphan*/  huge_pte_mkdirty (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  huge_pte_mkwrite (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  huge_pte_wrprotect (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mk_huge_pte (struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pte_mkhuge (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pte_mkyoung (int /*<<< orphan*/ ) ; 

__attribute__((used)) static pte_t make_huge_pte(struct vm_area_struct *vma, struct page *page,
				int writable)
{
	pte_t entry;

	if (writable) {
		entry = huge_pte_mkwrite(huge_pte_mkdirty(mk_huge_pte(page,
					 vma->vm_page_prot)));
	} else {
		entry = huge_pte_wrprotect(mk_huge_pte(page,
					   vma->vm_page_prot));
	}
	entry = pte_mkyoung(entry);
	entry = pte_mkhuge(entry);
	entry = arch_make_huge_pte(entry, vma, page, writable);

	return entry;
}