#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct rpc_message {int /*<<< orphan*/  rpc_cred; struct nfs_fattr* rpc_resp; struct nfs3_sattrargs* rpc_argp; int /*<<< orphan*/ * rpc_proc; } ;
struct nfs_fattr {int dummy; } ;
struct nfs3_sattrargs {struct iattr* sattr; int /*<<< orphan*/  fh; } ;
struct inode {int dummy; } ;
struct iattr {int ia_valid; int /*<<< orphan*/  ia_file; } ;
struct dentry {int dummy; } ;
struct TYPE_2__ {int cache_validity; } ;

/* Variables and functions */
 int ATTR_FILE ; 
 size_t NFS3PROC_SETATTR ; 
 int /*<<< orphan*/  NFS_CLIENT (struct inode*) ; 
 int /*<<< orphan*/  NFS_FH (struct inode*) ; 
 TYPE_1__* NFS_I (struct inode*) ; 
 int NFS_INO_INVALID_ACL ; 
 struct inode* d_inode (struct dentry*) ; 
 int /*<<< orphan*/  dprintk (char*,...) ; 
 int /*<<< orphan*/ * nfs3_procedures ; 
 int /*<<< orphan*/  nfs_fattr_init (struct nfs_fattr*) ; 
 int /*<<< orphan*/  nfs_file_cred (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfs_setattr_update_inode (struct inode*,struct iattr*,struct nfs_fattr*) ; 
 int /*<<< orphan*/  nfs_zap_acl_cache (struct inode*) ; 
 int rpc_call_sync (int /*<<< orphan*/ ,struct rpc_message*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
nfs3_proc_setattr(struct dentry *dentry, struct nfs_fattr *fattr,
			struct iattr *sattr)
{
	struct inode *inode = d_inode(dentry);
	struct nfs3_sattrargs	arg = {
		.fh		= NFS_FH(inode),
		.sattr		= sattr,
	};
	struct rpc_message msg = {
		.rpc_proc	= &nfs3_procedures[NFS3PROC_SETATTR],
		.rpc_argp	= &arg,
		.rpc_resp	= fattr,
	};
	int	status;

	dprintk("NFS call  setattr\n");
	if (sattr->ia_valid & ATTR_FILE)
		msg.rpc_cred = nfs_file_cred(sattr->ia_file);
	nfs_fattr_init(fattr);
	status = rpc_call_sync(NFS_CLIENT(inode), &msg, 0);
	if (status == 0) {
		if (NFS_I(inode)->cache_validity & NFS_INO_INVALID_ACL)
			nfs_zap_acl_cache(inode);
		nfs_setattr_update_inode(inode, sattr, fattr);
	}
	dprintk("NFS reply setattr: %d\n", status);
	return status;
}