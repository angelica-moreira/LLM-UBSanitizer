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
struct task_struct {TYPE_1__* signal; } ;
struct TYPE_2__ {int /*<<< orphan*/  cred_guard_mutex; } ;

/* Variables and functions */
 int EPERM ; 
 int /*<<< orphan*/  PTRACE_MODE_ATTACH_FSCREDS ; 
 int mutex_lock_killable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptrace_may_access (struct task_struct*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int lock_trace(struct task_struct *task)
{
	int err = mutex_lock_killable(&task->signal->cred_guard_mutex);
	if (err)
		return err;
	if (!ptrace_may_access(task, PTRACE_MODE_ATTACH_FSCREDS)) {
		mutex_unlock(&task->signal->cred_guard_mutex);
		return -EPERM;
	}
	return 0;
}