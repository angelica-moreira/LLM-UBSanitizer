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
 int /*<<< orphan*/  encode_mntdirpath (struct xdr_stream*,void const*) ; 

__attribute__((used)) static void mnt_xdr_enc_dirpath(struct rpc_rqst *req, struct xdr_stream *xdr,
				const void *dirpath)
{
	encode_mntdirpath(xdr, dirpath);
}