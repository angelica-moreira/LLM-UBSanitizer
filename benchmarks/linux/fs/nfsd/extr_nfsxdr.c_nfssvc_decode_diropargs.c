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
struct svc_rqst {struct nfsd_diropargs* rq_argp; } ;
struct nfsd_diropargs {int /*<<< orphan*/  len; int /*<<< orphan*/  name; int /*<<< orphan*/  fh; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/ * decode_fh (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * decode_filename (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int xdr_argsize_check (struct svc_rqst*,int /*<<< orphan*/ *) ; 

int
nfssvc_decode_diropargs(struct svc_rqst *rqstp, __be32 *p)
{
	struct nfsd_diropargs *args = rqstp->rq_argp;

	if (!(p = decode_fh(p, &args->fh))
	 || !(p = decode_filename(p, &args->name, &args->len)))
		return 0;

	return xdr_argsize_check(rqstp, p);
}