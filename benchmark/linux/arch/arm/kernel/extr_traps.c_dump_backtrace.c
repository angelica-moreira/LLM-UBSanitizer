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
 int /*<<< orphan*/  c_backtrace (unsigned int,unsigned int) ; 
 struct task_struct* current ; 
 scalar_t__ end_of_stack (struct task_struct*) ; 
 unsigned int frame_pointer (struct pt_regs*) ; 
 int /*<<< orphan*/  pr_cont (char*,...) ; 
 int /*<<< orphan*/  printk (char*) ; 
 unsigned int processor_mode (struct pt_regs*) ; 
 unsigned int thread_saved_fp (struct task_struct*) ; 
 scalar_t__ verify_stack (unsigned int) ; 

__attribute__((used)) static void dump_backtrace(struct pt_regs *regs, struct task_struct *tsk)
{
	unsigned int fp, mode;
	int ok = 1;

	printk("Backtrace: ");

	if (!tsk)
		tsk = current;

	if (regs) {
		fp = frame_pointer(regs);
		mode = processor_mode(regs);
	} else if (tsk != current) {
		fp = thread_saved_fp(tsk);
		mode = 0x10;
	} else {
		asm("mov %0, fp" : "=r" (fp) : : "cc");
		mode = 0x10;
	}

	if (!fp) {
		pr_cont("no frame pointer");
		ok = 0;
	} else if (verify_stack(fp)) {
		pr_cont("invalid frame pointer 0x%08x", fp);
		ok = 0;
	} else if (fp < (unsigned long)end_of_stack(tsk))
		pr_cont("frame pointer underflow");
	pr_cont("\n");

	if (ok)
		c_backtrace(fp, mode);
}