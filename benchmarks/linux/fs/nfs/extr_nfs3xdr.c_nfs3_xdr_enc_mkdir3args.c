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
struct nfs3_mkdirargs {int /*<<< orphan*/  sattr; int /*<<< orphan*/  len; int /*<<< orphan*/  name; int /*<<< orphan*/  fh; } ;

/* Variables and functions */
 int /*<<< orphan*/  encode_diropargs3 (struct xdr_stream*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  encode_sattr3 (struct xdr_stream*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rpc_rqst_userns (struct rpc_rqst*) ; 

__attribute__((used)) static void nfs3_xdr_enc_mkdir3args(struct rpc_rqst *req,
				    struct xdr_stream *xdr,
				    const void *data)
{
	const struct nfs3_mkdirargs *args = data;

	encode_diropargs3(xdr, args->fh, args->name, args->len);
	encode_sattr3(xdr, args->sattr, rpc_rqst_userns(req));
}