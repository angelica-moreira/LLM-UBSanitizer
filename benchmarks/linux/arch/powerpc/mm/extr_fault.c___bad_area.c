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
struct pt_regs {int dummy; } ;
struct mm_struct {int /*<<< orphan*/  mmap_sem; } ;
struct TYPE_2__ {struct mm_struct* mm; } ;

/* Variables and functions */
 int __bad_area_nosemaphore (struct pt_regs*,unsigned long,int) ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int __bad_area(struct pt_regs *regs, unsigned long address, int si_code)
{
	struct mm_struct *mm = current->mm;

	/*
	 * Something tried to access memory that isn't in our memory map..
	 * Fix it, but check if it's kernel or user first..
	 */
	up_read(&mm->mmap_sem);

	return __bad_area_nosemaphore(regs, address, si_code);
}