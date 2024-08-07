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
struct rpc_task {int dummy; } ;
struct nfs4_sequence_res {int dummy; } ;

/* Variables and functions */
 int nfs40_sequence_done (struct rpc_task*,struct nfs4_sequence_res*) ; 

__attribute__((used)) static int nfs4_sequence_process(struct rpc_task *task, struct nfs4_sequence_res *res)
{
	return nfs40_sequence_done(task, res);
}