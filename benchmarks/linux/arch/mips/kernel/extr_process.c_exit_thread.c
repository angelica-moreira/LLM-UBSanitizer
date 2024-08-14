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
struct task_struct {int dummy; } ;
struct TYPE_2__ {int flags; } ;

/* Variables and functions */
 int PF_KTHREAD ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/  dsemul_thread_cleanup (struct task_struct*) ; 

void exit_thread(struct task_struct *tsk)
{
	/*
	 * User threads may have allocated a delay slot emulation frame.
	 * If so, clean up that allocation.
	 */
	if (!(current->flags & PF_KTHREAD))
		dsemul_thread_cleanup(tsk);
}