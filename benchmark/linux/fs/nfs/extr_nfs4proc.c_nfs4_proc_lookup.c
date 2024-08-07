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
struct rpc_clnt {int dummy; } ;
struct qstr {int dummy; } ;
struct nfs_fh {int dummy; } ;
struct nfs_fattr {int dummy; } ;
struct nfs4_label {int dummy; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 struct rpc_clnt* NFS_CLIENT (struct inode*) ; 
 int nfs4_proc_lookup_common (struct rpc_clnt**,struct inode*,struct qstr const*,struct nfs_fh*,struct nfs_fattr*,struct nfs4_label*) ; 
 int /*<<< orphan*/  nfs_fixup_secinfo_attributes (struct nfs_fattr*) ; 
 int /*<<< orphan*/  rpc_shutdown_client (struct rpc_clnt*) ; 

__attribute__((used)) static int nfs4_proc_lookup(struct inode *dir, const struct qstr *name,
			    struct nfs_fh *fhandle, struct nfs_fattr *fattr,
			    struct nfs4_label *label)
{
	int status;
	struct rpc_clnt *client = NFS_CLIENT(dir);

	status = nfs4_proc_lookup_common(&client, dir, name, fhandle, fattr, label);
	if (client != NFS_CLIENT(dir)) {
		rpc_shutdown_client(client);
		nfs_fixup_secinfo_attributes(fattr);
	}
	return status;
}