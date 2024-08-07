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

/* Variables and functions */
 scalar_t__ MM_CTXT_NO_ASID ; 
 unsigned long PAGE_MASK ; 
 scalar_t__ asid_mm (int /*<<< orphan*/ ,unsigned int const) ; 
 unsigned long hw_pid (int /*<<< orphan*/ ,unsigned int const) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 unsigned int smp_processor_id () ; 
 int /*<<< orphan*/  tlb_entry_erase (unsigned long) ; 
 int /*<<< orphan*/  utlb_invalidate () ; 

void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
	const unsigned int cpu = smp_processor_id();
	unsigned long flags;

	/* Note that it is critical that interrupts are DISABLED between
	 * checking the ASID and using it flush the TLB entry
	 */
	local_irq_save(flags);

	if (asid_mm(vma->vm_mm, cpu) != MM_CTXT_NO_ASID) {
		tlb_entry_erase((page & PAGE_MASK) | hw_pid(vma->vm_mm, cpu));
		utlb_invalidate();
	}

	local_irq_restore(flags);
}