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
struct svc_rqst {struct nfsd3_renameres* rq_resp; } ;
struct nfsd3_renameres {int /*<<< orphan*/  tfh; int /*<<< orphan*/  ffh; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/ * encode_wcc_data (struct svc_rqst*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int xdr_ressize_check (struct svc_rqst*,int /*<<< orphan*/ *) ; 

int
nfs3svc_encode_renameres(struct svc_rqst *rqstp, __be32 *p)
{
	struct nfsd3_renameres *resp = rqstp->rq_resp;

	p = encode_wcc_data(rqstp, p, &resp->ffh);
	p = encode_wcc_data(rqstp, p, &resp->tfh);
	return xdr_ressize_check(rqstp, p);
}