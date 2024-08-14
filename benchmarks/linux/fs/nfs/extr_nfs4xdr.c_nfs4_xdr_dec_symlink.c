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
struct xdr_stream {int dummy; } ;
struct rpc_rqst {int dummy; } ;

/* Variables and functions */
 int nfs4_xdr_dec_create (struct rpc_rqst*,struct xdr_stream*,void*) ; 

__attribute__((used)) static int nfs4_xdr_dec_symlink(struct rpc_rqst *rqstp, struct xdr_stream *xdr,
				void *res)
{
	return nfs4_xdr_dec_create(rqstp, xdr, res);
}