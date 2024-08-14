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
struct svc_rqst {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  NLMPROC_UNLOCK_RES ; 
 int /*<<< orphan*/  __nlm4svc_proc_unlock ; 
 int /*<<< orphan*/  dprintk (char*) ; 
 int /*<<< orphan*/  nlm4svc_callback (struct svc_rqst*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __be32 nlm4svc_proc_unlock_msg(struct svc_rqst *rqstp)
{
	dprintk("lockd: UNLOCK_MSG    called\n");
	return nlm4svc_callback(rqstp, NLMPROC_UNLOCK_RES, __nlm4svc_proc_unlock);
}