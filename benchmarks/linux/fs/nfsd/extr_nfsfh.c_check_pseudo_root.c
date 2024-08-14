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
struct svc_rqst {int dummy; } ;
struct TYPE_2__ {struct dentry* dentry; } ;
struct svc_export {int ex_flags; TYPE_1__ ex_path; } ;
struct dentry {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int NFSEXP_V4ROOT ; 
 int /*<<< orphan*/  d_is_dir (struct dentry*) ; 
 int /*<<< orphan*/  d_is_symlink (struct dentry*) ; 
 int /*<<< orphan*/  nfs_ok ; 
 int /*<<< orphan*/  nfsd_v4client (struct svc_rqst*) ; 
 int /*<<< orphan*/  nfserr_stale ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline __be32 check_pseudo_root(struct svc_rqst *rqstp,
	struct dentry *dentry, struct svc_export *exp)
{
	if (!(exp->ex_flags & NFSEXP_V4ROOT))
		return nfs_ok;
	/*
	 * v2/v3 clients have no need for the V4ROOT export--they use
	 * the mount protocl instead; also, further V4ROOT checks may be
	 * in v4-specific code, in which case v2/v3 clients could bypass
	 * them.
	 */
	if (!nfsd_v4client(rqstp))
		return nfserr_stale;
	/*
	 * We're exposing only the directories and symlinks that have to be
	 * traversed on the way to real exports:
	 */
	if (unlikely(!d_is_dir(dentry) &&
		     !d_is_symlink(dentry)))
		return nfserr_stale;
	/*
	 * A pseudoroot export gives permission to access only one
	 * single directory; the kernel has to make another upcall
	 * before granting access to anything else under it:
	 */
	if (unlikely(dentry != exp->ex_path.dentry))
		return nfserr_stale;
	return nfs_ok;
}