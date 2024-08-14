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
struct svc_rqst {struct nlm_res* rq_resp; struct nlm_args* rq_argp; } ;
struct nlm_res {scalar_t__ status; int /*<<< orphan*/  cookie; } ;
struct nlm_host {int dummy; } ;
struct nlm_file {int dummy; } ;
struct nlm_args {int /*<<< orphan*/  lock; int /*<<< orphan*/  reclaim; int /*<<< orphan*/  cookie; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  SVC_NET (struct svc_rqst*) ; 
 int /*<<< orphan*/  dprintk (char*,...) ; 
 scalar_t__ locks_in_grace (int /*<<< orphan*/ ) ; 
 scalar_t__ nlm4svc_retrieve_args (struct svc_rqst*,struct nlm_args*,struct nlm_host**,struct nlm_file**) ; 
 scalar_t__ nlm_drop_reply ; 
 scalar_t__ nlm_lck_denied_grace_period ; 
 int /*<<< orphan*/  nlm_release_file (struct nlm_file*) ; 
 int /*<<< orphan*/  nlmsvc_release_host (struct nlm_host*) ; 
 int /*<<< orphan*/  nlmsvc_release_lockowner (int /*<<< orphan*/ *) ; 
 scalar_t__ nlmsvc_share_file (struct nlm_host*,struct nlm_file*,struct nlm_args*) ; 
 int /*<<< orphan*/  ntohl (scalar_t__) ; 
 int /*<<< orphan*/  rpc_drop_reply ; 
 int /*<<< orphan*/  rpc_success ; 

__attribute__((used)) static __be32
nlm4svc_proc_share(struct svc_rqst *rqstp)
{
	struct nlm_args *argp = rqstp->rq_argp;
	struct nlm_res *resp = rqstp->rq_resp;
	struct nlm_host	*host;
	struct nlm_file	*file;

	dprintk("lockd: SHARE         called\n");

	resp->cookie = argp->cookie;

	/* Don't accept new lock requests during grace period */
	if (locks_in_grace(SVC_NET(rqstp)) && !argp->reclaim) {
		resp->status = nlm_lck_denied_grace_period;
		return rpc_success;
	}

	/* Obtain client and file */
	if ((resp->status = nlm4svc_retrieve_args(rqstp, argp, &host, &file)))
		return resp->status == nlm_drop_reply ? rpc_drop_reply :rpc_success;

	/* Now try to create the share */
	resp->status = nlmsvc_share_file(host, file, argp);

	dprintk("lockd: SHARE         status %d\n", ntohl(resp->status));
	nlmsvc_release_lockowner(&argp->lock);
	nlmsvc_release_host(host);
	nlm_release_file(file);
	return rpc_success;
}