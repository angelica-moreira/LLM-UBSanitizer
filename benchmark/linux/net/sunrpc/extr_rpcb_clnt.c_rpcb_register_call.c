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
struct sunrpc_net {int /*<<< orphan*/  rpcb_is_af_local; } ;
struct rpc_message {int* rpc_resp; } ;
struct rpc_clnt {int dummy; } ;

/* Variables and functions */
 int EACCES ; 
 int RPC_TASK_NOCONNECT ; 
 int RPC_TASK_SOFTCONN ; 
 int /*<<< orphan*/  dprintk (char*,int) ; 
 int rpc_call_sync (struct rpc_clnt*,struct rpc_message*,int) ; 

__attribute__((used)) static int rpcb_register_call(struct sunrpc_net *sn, struct rpc_clnt *clnt, struct rpc_message *msg, bool is_set)
{
	int flags = RPC_TASK_NOCONNECT;
	int error, result = 0;

	if (is_set || !sn->rpcb_is_af_local)
		flags = RPC_TASK_SOFTCONN;
	msg->rpc_resp = &result;

	error = rpc_call_sync(clnt, msg, flags);
	if (error < 0) {
		dprintk("RPC:       failed to contact local rpcbind "
				"server (errno %d).\n", -error);
		return error;
	}

	if (!result)
		return -EACCES;
	return 0;
}