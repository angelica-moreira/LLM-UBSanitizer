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
 int /*<<< orphan*/  flush_tlb_mm (int /*<<< orphan*/ ) ; 

void
flush_tlb_range(struct vm_area_struct *vma, unsigned long start, unsigned long end)
{
	/* On the Alpha we always flush the whole user tlb.  */
	flush_tlb_mm(vma->vm_mm);
}