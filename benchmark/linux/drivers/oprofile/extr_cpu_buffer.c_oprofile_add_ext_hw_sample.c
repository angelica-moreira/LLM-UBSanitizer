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
struct task_struct {int dummy; } ;
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __oprofile_add_ext_sample (unsigned long,struct pt_regs* const,unsigned long,int,struct task_struct*) ; 

void oprofile_add_ext_hw_sample(unsigned long pc, struct pt_regs * const regs,
				unsigned long event, int is_kernel,
				struct task_struct *task)
{
	__oprofile_add_ext_sample(pc, regs, event, is_kernel, task);
}