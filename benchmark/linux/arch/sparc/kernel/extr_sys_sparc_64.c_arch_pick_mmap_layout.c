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
struct rlimit {unsigned long rlim_cur; } ;
struct mm_struct {int /*<<< orphan*/  get_unmapped_area; scalar_t__ mmap_base; } ;
struct TYPE_2__ {int personality; } ;

/* Variables and functions */
 int ADDR_COMPAT_LAYOUT ; 
 scalar_t__ PAGE_ALIGN (unsigned long) ; 
 unsigned long RLIM_INFINITY ; 
 unsigned long STACK_TOP32 ; 
 scalar_t__ TASK_UNMAPPED_BASE ; 
 int /*<<< orphan*/  TIF_32BIT ; 
 int /*<<< orphan*/  arch_get_unmapped_area ; 
 int /*<<< orphan*/  arch_get_unmapped_area_topdown ; 
 TYPE_1__* current ; 
 unsigned long mmap_rnd () ; 
 scalar_t__ sysctl_legacy_va_layout ; 
 int /*<<< orphan*/  test_thread_flag (int /*<<< orphan*/ ) ; 

void arch_pick_mmap_layout(struct mm_struct *mm, struct rlimit *rlim_stack)
{
	unsigned long random_factor = mmap_rnd();
	unsigned long gap;

	/*
	 * Fall back to the standard layout if the personality
	 * bit is set, or if the expected stack growth is unlimited:
	 */
	gap = rlim_stack->rlim_cur;
	if (!test_thread_flag(TIF_32BIT) ||
	    (current->personality & ADDR_COMPAT_LAYOUT) ||
	    gap == RLIM_INFINITY ||
	    sysctl_legacy_va_layout) {
		mm->mmap_base = TASK_UNMAPPED_BASE + random_factor;
		mm->get_unmapped_area = arch_get_unmapped_area;
	} else {
		/* We know it's 32-bit */
		unsigned long task_size = STACK_TOP32;

		if (gap < 128 * 1024 * 1024)
			gap = 128 * 1024 * 1024;
		if (gap > (task_size / 6 * 5))
			gap = (task_size / 6 * 5);

		mm->mmap_base = PAGE_ALIGN(task_size - gap - random_factor);
		mm->get_unmapped_area = arch_get_unmapped_area_topdown;
	}
}