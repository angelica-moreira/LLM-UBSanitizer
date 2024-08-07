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
typedef  int umode_t ;
struct vfsmount {int dummy; } ;
struct spu_gang {int /*<<< orphan*/  aff_mutex; } ;
struct spu_context {int dummy; } ;
struct path {struct dentry* dentry; struct vfsmount* mnt; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct dentry {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  i_ctx; struct spu_gang* i_gang; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_NICE ; 
 int EINVAL ; 
 int ENODEV ; 
 int EPERM ; 
 scalar_t__ IS_ERR (struct spu_context*) ; 
 int PTR_ERR (struct spu_context*) ; 
 TYPE_1__* SPUFS_I (struct inode*) ; 
 int SPU_CREATE_AFFINITY_MEM ; 
 int SPU_CREATE_AFFINITY_SPU ; 
 int SPU_CREATE_ISOLATE ; 
 int SPU_CREATE_NOSCHED ; 
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 struct inode* d_inode (struct dentry*) ; 
 int /*<<< orphan*/  isolated_loader ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_spu_context (struct spu_context*) ; 
 struct spu_context* spufs_assert_affinity (int,struct spu_gang*,struct file*) ; 
 int spufs_context_open (struct path*) ; 
 int spufs_mkdir (struct inode*,struct dentry*,int,int) ; 
 int /*<<< orphan*/  spufs_rmdir (struct inode*,struct dentry*) ; 
 int /*<<< orphan*/  spufs_set_affinity (int,int /*<<< orphan*/ ,struct spu_context*) ; 

__attribute__((used)) static int
spufs_create_context(struct inode *inode, struct dentry *dentry,
			struct vfsmount *mnt, int flags, umode_t mode,
			struct file *aff_filp)
{
	int ret;
	int affinity;
	struct spu_gang *gang;
	struct spu_context *neighbor;
	struct path path = {.mnt = mnt, .dentry = dentry};

	if ((flags & SPU_CREATE_NOSCHED) &&
	    !capable(CAP_SYS_NICE))
		return -EPERM;

	if ((flags & (SPU_CREATE_NOSCHED | SPU_CREATE_ISOLATE))
	    == SPU_CREATE_ISOLATE)
		return -EINVAL;

	if ((flags & SPU_CREATE_ISOLATE) && !isolated_loader)
		return -ENODEV;

	gang = NULL;
	neighbor = NULL;
	affinity = flags & (SPU_CREATE_AFFINITY_MEM | SPU_CREATE_AFFINITY_SPU);
	if (affinity) {
		gang = SPUFS_I(inode)->i_gang;
		if (!gang)
			return -EINVAL;
		mutex_lock(&gang->aff_mutex);
		neighbor = spufs_assert_affinity(flags, gang, aff_filp);
		if (IS_ERR(neighbor)) {
			ret = PTR_ERR(neighbor);
			goto out_aff_unlock;
		}
	}

	ret = spufs_mkdir(inode, dentry, flags, mode & 0777);
	if (ret)
		goto out_aff_unlock;

	if (affinity) {
		spufs_set_affinity(flags, SPUFS_I(d_inode(dentry))->i_ctx,
								neighbor);
		if (neighbor)
			put_spu_context(neighbor);
	}

	ret = spufs_context_open(&path);
	if (ret < 0)
		WARN_ON(spufs_rmdir(inode, dentry));

out_aff_unlock:
	if (affinity)
		mutex_unlock(&gang->aff_mutex);
	return ret;
}