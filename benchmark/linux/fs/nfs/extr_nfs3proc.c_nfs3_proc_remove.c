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
struct rpc_message {struct nfs_removeres* rpc_resp; struct nfs_removeargs* rpc_argp; int /*<<< orphan*/ * rpc_proc; } ;
struct nfs_removeres {int /*<<< orphan*/ * dir_attr; } ;
struct nfs_removeargs {int /*<<< orphan*/  name; int /*<<< orphan*/  fh; } ;
struct inode {int dummy; } ;
struct dentry {int /*<<< orphan*/  d_name; } ;

/* Variables and functions */
 int ENOMEM ; 
 size_t NFS3PROC_REMOVE ; 
 int /*<<< orphan*/  NFS_CLIENT (struct inode*) ; 
 int /*<<< orphan*/  NFS_FH (struct inode*) ; 
 int /*<<< orphan*/  dprintk (char*,...) ; 
 int /*<<< orphan*/ * nfs3_procedures ; 
 int /*<<< orphan*/ * nfs_alloc_fattr () ; 
 int /*<<< orphan*/  nfs_free_fattr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nfs_post_op_update_inode (struct inode*,int /*<<< orphan*/ *) ; 
 int rpc_call_sync (int /*<<< orphan*/ ,struct rpc_message*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
nfs3_proc_remove(struct inode *dir, struct dentry *dentry)
{
	struct nfs_removeargs arg = {
		.fh = NFS_FH(dir),
		.name = dentry->d_name,
	};
	struct nfs_removeres res;
	struct rpc_message msg = {
		.rpc_proc = &nfs3_procedures[NFS3PROC_REMOVE],
		.rpc_argp = &arg,
		.rpc_resp = &res,
	};
	int status = -ENOMEM;

	dprintk("NFS call  remove %pd2\n", dentry);
	res.dir_attr = nfs_alloc_fattr();
	if (res.dir_attr == NULL)
		goto out;

	status = rpc_call_sync(NFS_CLIENT(dir), &msg, 0);
	nfs_post_op_update_inode(dir, res.dir_attr);
	nfs_free_fattr(res.dir_attr);
out:
	dprintk("NFS reply remove: %d\n", status);
	return status;
}