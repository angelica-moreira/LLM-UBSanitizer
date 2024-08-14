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
struct nfs_server {int /*<<< orphan*/  pnfs_blksize; } ;
struct nfs_fsinfo {int /*<<< orphan*/  blksize; int /*<<< orphan*/  fattr; } ;
struct nfs_fh {int dummy; } ;

/* Variables and functions */
 int nfs4_do_fsinfo (struct nfs_server*,struct nfs_fh*,struct nfs_fsinfo*) ; 
 int /*<<< orphan*/  nfs_fattr_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_pnfs_layoutdriver (struct nfs_server*,struct nfs_fh*,struct nfs_fsinfo*) ; 

__attribute__((used)) static int nfs4_proc_fsinfo(struct nfs_server *server, struct nfs_fh *fhandle, struct nfs_fsinfo *fsinfo)
{
	int error;

	nfs_fattr_init(fsinfo->fattr);
	error = nfs4_do_fsinfo(server, fhandle, fsinfo);
	if (error == 0) {
		/* block layout checks this! */
		server->pnfs_blksize = fsinfo->blksize;
		set_pnfs_layoutdriver(server, fhandle, fsinfo);
	}

	return error;
}