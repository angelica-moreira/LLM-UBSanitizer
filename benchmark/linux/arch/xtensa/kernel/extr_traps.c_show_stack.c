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

/* Variables and functions */
 int kstack_depth_to_print ; 
 scalar_t__ kstack_end (unsigned long*) ; 
 int /*<<< orphan*/  pr_cont (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  show_trace (struct task_struct*,unsigned long*) ; 
 unsigned long* stack_pointer (struct task_struct*) ; 

void show_stack(struct task_struct *task, unsigned long *sp)
{
	int i = 0;
	unsigned long *stack;

	if (!sp)
		sp = stack_pointer(task);
	stack = sp;

	pr_info("Stack:\n");

	for (i = 0; i < kstack_depth_to_print; i++) {
		if (kstack_end(sp))
			break;
		pr_cont(" %08lx", *sp++);
		if (i % 8 == 7)
			pr_cont("\n");
	}
	show_trace(task, stack);
}