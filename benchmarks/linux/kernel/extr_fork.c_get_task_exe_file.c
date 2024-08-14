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
struct task_struct {int flags; struct mm_struct* mm; } ;
struct mm_struct {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int PF_KTHREAD ; 
 struct file* get_mm_exe_file (struct mm_struct*) ; 
 int /*<<< orphan*/  task_lock (struct task_struct*) ; 
 int /*<<< orphan*/  task_unlock (struct task_struct*) ; 

struct file *get_task_exe_file(struct task_struct *task)
{
	struct file *exe_file = NULL;
	struct mm_struct *mm;

	task_lock(task);
	mm = task->mm;
	if (mm) {
		if (!(task->flags & PF_KTHREAD))
			exe_file = get_mm_exe_file(mm);
	}
	task_unlock(task);
	return exe_file;
}