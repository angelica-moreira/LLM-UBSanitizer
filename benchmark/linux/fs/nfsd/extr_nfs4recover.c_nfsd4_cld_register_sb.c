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
struct super_block {int dummy; } ;
struct rpc_pipe {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOENT ; 
 struct dentry* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NFSD_CLD_PIPE ; 
 int /*<<< orphan*/  NFSD_PIPE_DIR ; 
 int /*<<< orphan*/  dput (struct dentry*) ; 
 struct dentry* rpc_d_lookup_sb (struct super_block*,int /*<<< orphan*/ ) ; 
 struct dentry* rpc_mkpipe_dentry (struct dentry*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct rpc_pipe*) ; 

__attribute__((used)) static struct dentry *
nfsd4_cld_register_sb(struct super_block *sb, struct rpc_pipe *pipe)
{
	struct dentry *dir, *dentry;

	dir = rpc_d_lookup_sb(sb, NFSD_PIPE_DIR);
	if (dir == NULL)
		return ERR_PTR(-ENOENT);
	dentry = rpc_mkpipe_dentry(dir, NFSD_CLD_PIPE, NULL, pipe);
	dput(dir);
	return dentry;
}