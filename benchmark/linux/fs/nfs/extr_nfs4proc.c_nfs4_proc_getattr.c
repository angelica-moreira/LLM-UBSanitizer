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
struct nfs_server {int dummy; } ;
struct nfs_fh {int dummy; } ;
struct nfs_fattr {int dummy; } ;
struct nfs4_label {int dummy; } ;
struct nfs4_exception {int interruptible; scalar_t__ retry; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 int _nfs4_proc_getattr (struct nfs_server*,struct nfs_fh*,struct nfs_fattr*,struct nfs4_label*,struct inode*) ; 
 int nfs4_handle_exception (struct nfs_server*,int,struct nfs4_exception*) ; 
 int /*<<< orphan*/  trace_nfs4_getattr (struct nfs_server*,struct nfs_fh*,struct nfs_fattr*,int) ; 

__attribute__((used)) static int nfs4_proc_getattr(struct nfs_server *server, struct nfs_fh *fhandle,
				struct nfs_fattr *fattr, struct nfs4_label *label,
				struct inode *inode)
{
	struct nfs4_exception exception = {
		.interruptible = true,
	};
	int err;
	do {
		err = _nfs4_proc_getattr(server, fhandle, fattr, label, inode);
		trace_nfs4_getattr(server, fhandle, fattr, err);
		err = nfs4_handle_exception(server, err,
				&exception);
	} while (exception.retry);
	return err;
}