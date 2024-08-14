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
struct svc_rqst {struct nfsd3_getaclres* rq_resp; } ;
struct nfsd3_getaclres {int /*<<< orphan*/  acl_default; int /*<<< orphan*/  acl_access; int /*<<< orphan*/  fh; } ;

/* Variables and functions */
 int /*<<< orphan*/  fh_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  posix_acl_release (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nfs3svc_release_getacl(struct svc_rqst *rqstp)
{
	struct nfsd3_getaclres *resp = rqstp->rq_resp;

	fh_put(&resp->fh);
	posix_acl_release(resp->acl_access);
	posix_acl_release(resp->acl_default);
}