#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct trace_pid_list {int dummy; } ;
struct TYPE_4__ {TYPE_1__* data; } ;
struct trace_array {TYPE_2__ trace_buffer; int /*<<< orphan*/  filtered_pids; } ;
struct task_struct {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  ignore_pid; } ;

/* Variables and functions */
 struct trace_pid_list* rcu_dereference_sched (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  this_cpu_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  this_cpu_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_ignore_this_task (struct trace_pid_list*,struct task_struct*) ; 

__attribute__((used)) static void
event_filter_pid_sched_wakeup_probe_pre(void *data, struct task_struct *task)
{
	struct trace_array *tr = data;
	struct trace_pid_list *pid_list;

	/* Nothing to do if we are already tracing */
	if (!this_cpu_read(tr->trace_buffer.data->ignore_pid))
		return;

	pid_list = rcu_dereference_sched(tr->filtered_pids);

	this_cpu_write(tr->trace_buffer.data->ignore_pid,
		       trace_ignore_this_task(pid_list, task));
}