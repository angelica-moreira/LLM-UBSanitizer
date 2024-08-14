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
struct nfs_fh {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  encode_fhandle (struct xdr_stream*,struct nfs_fh const*) ; 

__attribute__((used)) static void nfs2_xdr_enc_fhandle(struct rpc_rqst *req,
				 struct xdr_stream *xdr,
				 const void *data)
{
	const struct nfs_fh *fh = data;

	encode_fhandle(xdr, fh);
}