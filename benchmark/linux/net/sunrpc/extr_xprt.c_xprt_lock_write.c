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
struct rpc_xprt {int /*<<< orphan*/  transport_lock; TYPE_1__* ops; struct rpc_task* snd_task; int /*<<< orphan*/  state; } ;
struct rpc_task {int dummy; } ;
struct TYPE_2__ {int (* reserve_xprt ) (struct rpc_xprt*,struct rpc_task*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  XPRT_LOCKED ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int stub1 (struct rpc_xprt*,struct rpc_task*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int xprt_lock_write(struct rpc_xprt *xprt, struct rpc_task *task)
{
	int retval;

	if (test_bit(XPRT_LOCKED, &xprt->state) && xprt->snd_task == task)
		return 1;
	spin_lock(&xprt->transport_lock);
	retval = xprt->ops->reserve_xprt(xprt, task);
	spin_unlock(&xprt->transport_lock);
	return retval;
}