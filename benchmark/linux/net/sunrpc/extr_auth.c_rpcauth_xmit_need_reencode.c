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
struct rpc_task {TYPE_1__* tk_rqstp; } ;
struct rpc_cred {TYPE_2__* cr_ops; } ;
struct TYPE_4__ {int (* crneed_reencode ) (struct rpc_task*) ;} ;
struct TYPE_3__ {struct rpc_cred* rq_cred; } ;

/* Variables and functions */
 int stub1 (struct rpc_task*) ; 

bool
rpcauth_xmit_need_reencode(struct rpc_task *task)
{
	struct rpc_cred *cred = task->tk_rqstp->rq_cred;

	if (!cred || !cred->cr_ops->crneed_reencode)
		return false;
	return cred->cr_ops->crneed_reencode(task);
}