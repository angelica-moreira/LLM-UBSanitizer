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
struct rpc_wait_queue {int dummy; } ;
struct rpc_task {int /*<<< orphan*/  tk_status; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETIMEDOUT ; 
 int /*<<< orphan*/  __rpc_add_timer (struct rpc_wait_queue*,struct rpc_task*,unsigned long) ; 
 int /*<<< orphan*/  __rpc_sleep_on_priority (struct rpc_wait_queue*,struct rpc_task*,unsigned char) ; 
 scalar_t__ time_is_after_jiffies (unsigned long) ; 

__attribute__((used)) static void __rpc_sleep_on_priority_timeout(struct rpc_wait_queue *q,
		struct rpc_task *task, unsigned long timeout,
		unsigned char queue_priority)
{
	if (time_is_after_jiffies(timeout)) {
		__rpc_sleep_on_priority(q, task, queue_priority);
		__rpc_add_timer(q, task, timeout);
	} else
		task->tk_status = -ETIMEDOUT;
}