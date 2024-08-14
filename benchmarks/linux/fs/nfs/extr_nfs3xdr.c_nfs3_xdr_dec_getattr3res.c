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
typedef  enum nfs_stat { ____Placeholder_nfs_stat } nfs_stat ;

/* Variables and functions */
 int NFS3_OK ; 
 int decode_fattr3 (struct xdr_stream*,void*,int /*<<< orphan*/ ) ; 
 int decode_nfsstat3 (struct xdr_stream*,int*) ; 
 int nfs3_stat_to_errno (int) ; 
 int /*<<< orphan*/  rpc_rqst_userns (struct rpc_rqst*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int nfs3_xdr_dec_getattr3res(struct rpc_rqst *req,
				    struct xdr_stream *xdr,
				    void *result)
{
	enum nfs_stat status;
	int error;

	error = decode_nfsstat3(xdr, &status);
	if (unlikely(error))
		goto out;
	if (status != NFS3_OK)
		goto out_default;
	error = decode_fattr3(xdr, result, rpc_rqst_userns(req));
out:
	return error;
out_default:
	return nfs3_stat_to_errno(status);
}