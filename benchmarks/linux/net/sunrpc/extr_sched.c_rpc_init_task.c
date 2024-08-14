#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct rpc_task_setup {int /*<<< orphan*/  rpc_op_cred; int /*<<< orphan*/  rpc_xprt; int /*<<< orphan*/  rpc_client; int /*<<< orphan*/  workqueue; scalar_t__ priority; int /*<<< orphan*/  callback_data; TYPE_1__* callback_ops; int /*<<< orphan*/  flags; } ;
struct rpc_task {int /*<<< orphan*/  tk_action; TYPE_1__* tk_ops; int /*<<< orphan*/  tk_op_cred; int /*<<< orphan*/  tk_xprt; int /*<<< orphan*/  tk_workqueue; int /*<<< orphan*/  tk_owner; scalar_t__ tk_priority; int /*<<< orphan*/  tk_task; int /*<<< orphan*/  tk_calldata; int /*<<< orphan*/  tk_flags; int /*<<< orphan*/  tk_count; } ;
struct TYPE_5__ {int /*<<< orphan*/  tgid; } ;
struct TYPE_4__ {int /*<<< orphan*/ * rpc_call_prepare; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 scalar_t__ RPC_PRIORITY_LOW ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 TYPE_2__* current ; 
 int /*<<< orphan*/  dprintk (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_rpccred (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct rpc_task*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rpc_init_task_statistics (struct rpc_task*) ; 
 int /*<<< orphan*/  rpc_prepare_task ; 
 int /*<<< orphan*/  rpc_task_get_xprt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  task_pid_nr (TYPE_2__*) ; 
 int /*<<< orphan*/  xprt_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rpc_init_task(struct rpc_task *task, const struct rpc_task_setup *task_setup_data)
{
	memset(task, 0, sizeof(*task));
	atomic_set(&task->tk_count, 1);
	task->tk_flags  = task_setup_data->flags;
	task->tk_ops = task_setup_data->callback_ops;
	task->tk_calldata = task_setup_data->callback_data;
	INIT_LIST_HEAD(&task->tk_task);

	task->tk_priority = task_setup_data->priority - RPC_PRIORITY_LOW;
	task->tk_owner = current->tgid;

	/* Initialize workqueue for async tasks */
	task->tk_workqueue = task_setup_data->workqueue;

	task->tk_xprt = rpc_task_get_xprt(task_setup_data->rpc_client,
			xprt_get(task_setup_data->rpc_xprt));

	task->tk_op_cred = get_rpccred(task_setup_data->rpc_op_cred);

	if (task->tk_ops->rpc_call_prepare != NULL)
		task->tk_action = rpc_prepare_task;

	rpc_init_task_statistics(task);

	dprintk("RPC:       new task initialized, procpid %u\n",
				task_pid_nr(current));
}