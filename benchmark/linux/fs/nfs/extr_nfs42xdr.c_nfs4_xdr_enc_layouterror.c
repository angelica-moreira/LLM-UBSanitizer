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
struct nfs42_layouterror_args {int num_errors; int /*<<< orphan*/ * errors; int /*<<< orphan*/  inode; int /*<<< orphan*/  seq_args; } ;
struct compound_hdr {int /*<<< orphan*/  minorversion; } ;

/* Variables and functions */
 int /*<<< orphan*/  NFS_FH (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  encode_compound_hdr (struct xdr_stream*,struct rpc_rqst*,struct compound_hdr*) ; 
 int /*<<< orphan*/  encode_layouterror (struct xdr_stream*,int /*<<< orphan*/ *,struct compound_hdr*) ; 
 int /*<<< orphan*/  encode_nops (struct compound_hdr*) ; 
 int /*<<< orphan*/  encode_putfh (struct xdr_stream*,int /*<<< orphan*/ ,struct compound_hdr*) ; 
 int /*<<< orphan*/  encode_sequence (struct xdr_stream*,int /*<<< orphan*/ *,struct compound_hdr*) ; 
 int /*<<< orphan*/  nfs4_xdr_minorversion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void nfs4_xdr_enc_layouterror(struct rpc_rqst *req,
				     struct xdr_stream *xdr,
				     const void *data)
{
	const struct nfs42_layouterror_args *args = data;
	struct compound_hdr hdr = {
		.minorversion = nfs4_xdr_minorversion(&args->seq_args),
	};
	int i;

	encode_compound_hdr(xdr, req, &hdr);
	encode_sequence(xdr, &args->seq_args, &hdr);
	encode_putfh(xdr, NFS_FH(args->inode), &hdr);
	for (i = 0; i < args->num_errors; i++)
		encode_layouterror(xdr, &args->errors[i], &hdr);
	encode_nops(&hdr);
}