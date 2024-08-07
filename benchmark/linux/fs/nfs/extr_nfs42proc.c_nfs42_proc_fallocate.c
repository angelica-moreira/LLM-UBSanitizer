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
struct rpc_message {int dummy; } ;
struct nfs_server {int dummy; } ;
struct nfs_lock_context {TYPE_1__* open_context; } ;
struct nfs4_exception {scalar_t__ retry; int /*<<< orphan*/  state; int /*<<< orphan*/  inode; } ;
struct file {int dummy; } ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_2__ {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 int EOPNOTSUPP ; 
 scalar_t__ IS_ERR (struct nfs_lock_context*) ; 
 struct nfs_server* NFS_SERVER (int /*<<< orphan*/ ) ; 
 int PTR_ERR (struct nfs_lock_context*) ; 
 int _nfs42_proc_fallocate (struct rpc_message*,struct file*,struct nfs_lock_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  file_inode (struct file*) ; 
 int nfs4_handle_exception (struct nfs_server*,int,struct nfs4_exception*) ; 
 int /*<<< orphan*/  nfs_file_open_context (struct file*) ; 
 struct nfs_lock_context* nfs_get_lock_context (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfs_put_lock_context (struct nfs_lock_context*) ; 

__attribute__((used)) static int nfs42_proc_fallocate(struct rpc_message *msg, struct file *filep,
				loff_t offset, loff_t len)
{
	struct nfs_server *server = NFS_SERVER(file_inode(filep));
	struct nfs4_exception exception = { };
	struct nfs_lock_context *lock;
	int err;

	lock = nfs_get_lock_context(nfs_file_open_context(filep));
	if (IS_ERR(lock))
		return PTR_ERR(lock);

	exception.inode = file_inode(filep);
	exception.state = lock->open_context->state;

	do {
		err = _nfs42_proc_fallocate(msg, filep, lock, offset, len);
		if (err == -ENOTSUPP) {
			err = -EOPNOTSUPP;
			break;
		}
		err = nfs4_handle_exception(server, err, &exception);
	} while (exception.retry);

	nfs_put_lock_context(lock);
	return err;
}