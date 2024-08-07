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
struct trace_pid_list {int /*<<< orphan*/  pids; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct trace_pid_list*) ; 
 int /*<<< orphan*/  vfree (int /*<<< orphan*/ ) ; 

void trace_free_pid_list(struct trace_pid_list *pid_list)
{
	vfree(pid_list->pids);
	kfree(pid_list);
}