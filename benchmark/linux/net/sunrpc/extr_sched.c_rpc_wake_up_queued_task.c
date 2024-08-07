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
struct rpc_wait_queue {int /*<<< orphan*/  lock; } ;
struct rpc_task {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RPC_IS_QUEUED (struct rpc_task*) ; 
 int /*<<< orphan*/  rpc_wake_up_task_queue_locked (struct rpc_wait_queue*,struct rpc_task*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

void rpc_wake_up_queued_task(struct rpc_wait_queue *queue, struct rpc_task *task)
{
	if (!RPC_IS_QUEUED(task))
		return;
	spin_lock(&queue->lock);
	rpc_wake_up_task_queue_locked(queue, task);
	spin_unlock(&queue->lock);
}