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
struct svc_rqst {int /*<<< orphan*/  rq_resp; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  __nlmsvc_proc_test (struct svc_rqst*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __be32
nlmsvc_proc_test(struct svc_rqst *rqstp)
{
	return __nlmsvc_proc_test(rqstp, rqstp->rq_resp);
}