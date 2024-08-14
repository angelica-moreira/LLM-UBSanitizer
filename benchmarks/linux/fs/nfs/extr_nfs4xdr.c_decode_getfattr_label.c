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
struct nfs_server {int dummy; } ;
struct nfs_fattr {int dummy; } ;
struct nfs4_label {int dummy; } ;

/* Variables and functions */
 int decode_getfattr_generic (struct xdr_stream*,struct nfs_fattr*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct nfs4_label*,struct nfs_server const*) ; 

__attribute__((used)) static int decode_getfattr_label(struct xdr_stream *xdr, struct nfs_fattr *fattr,
		struct nfs4_label *label, const struct nfs_server *server)
{
	return decode_getfattr_generic(xdr, fattr, NULL, NULL, label, server);
}